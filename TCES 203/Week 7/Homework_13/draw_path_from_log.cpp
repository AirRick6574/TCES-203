#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

/*
  draw_path_from_log.cpp
  Reads car_log.txt (simulation log) and generates a PPM image (car_path.ppm)
  that visually represents the car's path.
*/

struct RGB { unsigned char r, g, b; };
struct Image {
    int W, H;
    vector<RGB> pix;
    Image(int W, int H) : W(W), H(H), pix(W * H) {}
    void clear(RGB c) { fill(pix.begin(), pix.end(), c); }
    inline bool inside(int x, int y) const { return x >= 0 && y >= 0 && x < W && y < H; }
    void put(int x, int y, RGB c) { if (inside(x, y)) pix[y * W + x] = c; }
    void write(const string &path) {
        FILE *f = fopen(path.c_str(), "wb");
        if (!f) { perror("fopen"); return; }
        fprintf(f, "P6\n%d %d\n255\n", W, H);
        fwrite(pix.data(), 1, pix.size() * 3, f);
        fclose(f);
    }
};

// Colors
static const RGB COL_BG = {245, 247, 250};
static const RGB COL_GRID = {225, 230, 236};
static const RGB COL_AXIS = {200, 206, 214};
static const RGB COL_PATH = {50, 95, 220};
static const RGB COL_ARROW = {20, 50, 160};
static const RGB COL_START = {16, 175, 64};
static const RGB COL_END = {220, 50, 50};
static const RGB COL_CAM = {145, 60, 210};
static const RGB COL_BORDER = {180, 186, 194};

// Drawing helpers
void drawLine(Image &img, int x0, int y0, int x1, int y1, RGB col) {
    int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = -abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = dx + dy;
    while (true) {
        img.put(x0, y0, col);
        if (x0 == x1 && y0 == y1) break;
        int e2 = 2 * err;
        if (e2 >= dy) { err += dy; x0 += sx; }
        if (e2 <= dx) { err += dx; y0 += sy; }
    }
}

void drawThickLine(Image &img, int x0, int y0, int x1, int y1, int t, RGB col) {
    int dx = x1 - x0, dy = y1 - y0;
    double len = sqrt(dx * dx + dy * dy);
    if (len < 1e-6) return;
    double px = -dy / len, py = dx / len;
    for (int i = -t / 2; i <= t / 2; ++i) {
        int ox = int(px * i), oy = int(py * i);
        drawLine(img, x0 + ox, y0 + oy, x1 + ox, y1 + oy, col);
    }
}

void drawCircle(Image &img, int cx, int cy, int r, RGB col, bool fill = true) {
    for (int y = cy - r; y <= cy + r; ++y)
        for (int x = cx - r; x <= cx + r; ++x)
            if (img.inside(x, y)) {
                int dx = x - cx, dy = y - cy;
                int d2 = dx * dx + dy * dy;
                if (fill ? d2 <= r * r : abs(d2 - r * r) <= r) img.put(x, y, col);
            }
}

void drawX(Image &img, int cx, int cy, int s, int t, RGB col) {
    drawThickLine(img, cx - s, cy - s, cx + s, cy + s, t, col);
    drawThickLine(img, cx - s, cy + s, cx + s, cy - s, t, col);
}

void drawArrow(Image &img, int x0, int y0, int x1, int y1, int size, RGB col) {
    double dx = x1 - x0, dy = y1 - y0;
    double len = sqrt(dx * dx + dy * dy);
    if (len < 1e-6) return;
    dx /= len; dy /= len;
    int bx = int(x1 - dx * size);
    int by = int(y1 - dy * size);
    int px = int(-dy * (size / 2.0));
    int py = int(dx * (size / 2.0));
    drawThickLine(img, x1, y1, bx + px, by + py, 2, col);
    drawThickLine(img, x1, y1, bx - px, by - py, 2, col);
    drawThickLine(img, bx + px, by + py, bx - px, by - py, 2, col);
}

void drawGrid(Image &img, int step = 50, int boldEvery = 5) {
    for (int x = 0; x < img.W; x += step)
        for (int y = 0; y < img.H; ++y) img.put(x, y, COL_GRID);
    for (int y = 0; y < img.H; y += step)
        for (int x = 0; x < img.W; ++x) img.put(x, y, COL_GRID);
    int b = step * boldEvery;
    for (int x = 0; x < img.W; x += b)
        for (int y = 0; y < img.H; ++y) img.put(x, y, COL_AXIS);
    for (int y = 0; y < img.H; y += b)
        for (int x = 0; x < img.W; ++x) img.put(x, y, COL_AXIS);
}

void drawBorder(Image &img, int t = 3) {
    for (int i = 0; i < t; ++i) {
        for (int x = 0; x < img.W; ++x) {
            img.put(x, i, COL_BORDER);
            img.put(x, img.H - 1 - i, COL_BORDER);
        }
        for (int y = 0; y < img.H; ++y) {
            img.put(i, y, COL_BORDER);
            img.put(img.W - 1 - i, y, COL_BORDER);
        }
    }
}

enum Heading { NORTH, EAST, SOUTH, WEST };
struct Pt { double x = 0, y = 0; };

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Default to "car_log.txt" if no argument provided
    string logPath = (argc >= 2) ? string(argv[1]) : "car_log.txt";

    // Read log lines
    ifstream in(logPath);
    if (!in) {
        cerr << "Error: cannot open " << logPath << "\n";
        return 1;
    }

    vector<string> lines;
    string s;
    while (getline(in, s)) if (!s.empty()) lines.push_back(s);

    // Parse actions
    vector<string> actions;
    for (auto &line : lines) {
        if (line.find("Move Forward") != string::npos) actions.push_back("FWD");
        else if (line.find("Move Backward") != string::npos) actions.push_back("BWD");
        else if (line.find("Turn Left") != string::npos) actions.push_back("LFT");
        else if (line.find("Turn Right") != string::npos) actions.push_back("RGT");
        else if (line.find("Activate Camera") != string::npos) actions.push_back("CAM");
    }

    if (actions.empty()) {
        cerr << "No valid actions found in " << logPath << "\n";
        return 0;
    }

    // Simulate path
    Heading h = NORTH;
    Pt cur{0, 0};
    vector<Pt> path{cur}, cams;

    auto step = [&](Heading hh) {
        if (hh == NORTH) return Pt{0, 1};
        if (hh == EAST) return Pt{1, 0};
        if (hh == SOUTH) return Pt{0, -1};
        return Pt{-1, 0};
    };

    for (auto &a : actions) {
        if (a == "LFT") h = Heading((h + 3) % 4);
        else if (a == "RGT") h = Heading((h + 1) % 4);
        else if (a == "FWD") { Pt d = step(h); cur.x += d.x; cur.y += d.y; path.push_back(cur); }
        else if (a == "BWD") { Pt d = step(h); cur.x -= d.x; cur.y -= d.y; path.push_back(cur); }
        else if (a == "CAM") cams.push_back(cur);
    }

    // Bounds
    double minx = 1e9, maxx = -1e9, miny = 1e9, maxy = -1e9;
    for (auto &p : path) {
        minx = min(minx, p.x); maxx = max(maxx, p.x);
        miny = min(miny, p.y); maxy = max(maxy, p.y);
    }

    // Create image
    const int W = 1000, H = 1000, M = 100;
    Image img(W, H);
    img.clear(COL_BG);
    drawGrid(img, 50, 4);
    drawBorder(img, 4);

    // Scale & map
    double sx = (W - 2.0 * M) / max(1.0, maxx - minx);
    double sy = (H - 2.0 * M) / max(1.0, maxy - miny);
    double scale = min(sx, sy);
    auto mapX = [&](double x) { return int(round(M + (x - minx) * scale)); };
    auto mapY = [&](double y) { return int(round(H - M - (y - miny) * scale)); };

    // Draw path
    for (size_t i = 1; i < path.size(); ++i) {
        int x0 = mapX(path[i - 1].x), y0 = mapY(path[i - 1].y);
        int x1 = mapX(path[i].x), y1 = mapY(path[i].y);
        drawThickLine(img, x0, y0, x1, y1, 6, COL_PATH);
        drawArrow(img, x0, y0, x1, y1, 18, COL_ARROW);
    }

    // Start & End markers
    drawCircle(img, mapX(path.front().x), mapY(path.front().y), 10, COL_START, true);
    drawX(img, mapX(path.back().x), mapY(path.back().y), 10, 4, COL_END);

    // Camera markers
    for (auto &c : cams)
        drawCircle(img, mapX(c.x), mapY(c.y), 6, COL_CAM, true);

    img.write("car_path.ppm");
    cout << "✅ Wrote car_path.ppm (open with Preview or convert to PNG)\n";
    return 0;
}
