#define _CRT_SECURE_NO_WARNINGS
#include "Canvas.h"
#include <cstdlib>
#include <cstdio>

Canvas::Canvas(int width, int height) {
    this->width = width;
    this->height = height;
    this->canvas = new char*[height];
    // this->canvas = (char**) malloc(height * sizeof(char*));
    for (int i = 0; i < height; i++) {
        // canvas[i] = (char*) malloc(width * sizeof(char));
        canvas[i] = new char[width];
    }
    Clear();
}

void Canvas::DrawCircle(int x, int y, int ray, char ch) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int distance;
            distance = (x - j) * (x - j) + (y - i) * (y - i);
            if (distance <= ray * (ray + 1) && distance >= ray * (ray - 1))
                SetPoint(i, j, ch);
        }
    }
}

void Canvas::FillCircle(int x, int y, int ray, char ch) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int distance;
            distance = (x - j) * (x - j) + (y - i) * (y - i);
            if (distance <= ray * ray)
                SetPoint(i, j, ch);
        }
    }
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
    for (int i = left; i <= right; i++) {
        SetPoint(top, i, ch);
        SetPoint(bottom, i, ch);
    }
    for (int i = top; i <= bottom; i++) {
        SetPoint(i, left, ch);
        SetPoint(i, right, ch);
    }
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
    for (int i = left; i <= right; i++) {
        for (int j = top; j <= bottom; j++) {
            SetPoint(i, j, ch);
        }
    }
}

void Canvas::SetPoint(int x, int y, char ch) {
    canvas[x][y] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
    int m_new = 2 * (y2 - y1);
    int slope_error_new = m_new - (x2 - x1);
    for (int x = x1, y = y1; x <= x2; x++) {
        SetPoint(x, y, ch);
        slope_error_new += m_new;
        if (slope_error_new >= 0) {
            y++;
            slope_error_new -= 2 * (x2 - x1);
        }
    }
}

void Canvas::Print() {
    for (int i = 0; i < this->height; i++) {
        for (int j = 0; j < this->width; j++) {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
}

void Canvas::Clear() {
    for (int i = 0; i < this->height; i++)
        for (int j = 0; j < this->width; j++)
            SetPoint(i, j, ' ');
}
