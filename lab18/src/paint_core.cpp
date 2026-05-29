#include "paint_core.hpp"
#include <algorithm>   // std::min, std::max, std::transform, std::fill
#include <cmath>       // std::abs
#include <stack>       // std::stack
#include <iostream>
#include <vector>

extern std::stack<Canvas> undoStack;

template < typename T >
T minimum(T a, T b) {
    return a > b ? b : a;
}
template < typename T >
T maximum( T a, T b) {
    return a > b ? a : b;
}
// ========== Вспомогательная функция сохранения (уже готова) ==========
void saveToUndo(const Canvas& canvas) {
    undoStack.push(canvas);
}

// ========== 1. Очистка холста (оценка 3) ==========
void clearCanvas(Canvas& canvas) {
    for ( auto& row : canvas ) std::fill(row.begin(), row.end(), sf::Color::White);
    // TODO: заполнить весь холст белым цветом sf::Color::White
    // Использовать std::fill для каждой строки (или двойной цикл)
    // Подсказка: for (auto& row : canvas) std::fill(row.begin(), row.end(), sf::Color::White);
}

// ========== 2. Рисование пикселя (оценка 3) ==========
void drawPixel(Canvas& canvas, int x, int y, const sf::Color& color) {
        if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
            canvas[y][x] = color;
        }
    // TODO: проверить, что x и y в пределах [0, WIDTH-1] и [0, HEIGHT-1]
    // Если да, то присвоить canvas[y][x] = color
}

// ========== 3. Круглая кисть (оценка 3) ==========
void drawBrush(Canvas& canvas, int x, int y, const sf::Color& color, int radius) {
    for (int dx = -radius; dx <= radius; ++dx) {
        for (int dy = -radius; dy <= radius; ++dy) {
            if (dx*dx + dy*dy <= radius*radius) {
                drawPixel(canvas, x + dx, y + dy, color);
            }
        }
    }
}

    // TODO: закрасить круг с центром (x,y) радиусом radius
    // Перебрать все dx, dy от -radius до +radius, проверить dx*dx+dy*dy <= radius*radius
    // Вызвать drawPixel для (x+dx, y+dy)


// ========== 4. Прямоугольник (оценка 3) ==========
void drawRectangle(Canvas& canvas, int x1, int y1, int x2, int y2, const sf::Color& color) {
    saveToUndo(canvas);   // уже есть, не удалять
    int left = std::min(x1,x2);
    int right = std::max(x1,x2);
    int top = std::min(y1,y2);
    int bottom = std::max(y1,y2);
    for(int y = top; y<= bottom; y++) {
        for ( int x = left; x<= right; x++) {
            drawPixel(canvas,x,y,color);
        }
    }
    // TODO: вычислить left = min(x1,x2), right = max(x1,x2), top = min(y1,y2), bottom = max(y1,y2)
    // Двойной цикл for (int y = top; y <= bottom; ++y) for (int x = left; x <= right; ++x)
    // Вызвать drawPixel(canvas, x, y, color)
}

// ========== 5. Линия (Брезенхем) (оценка 4) ==========
void drawLine(Canvas& canvas, int x1, int y1, int x2, int y2, const sf::Color& color) {
    saveToUndo(canvas);
    int dx = std::abs(x2 - x1);
    int dy = std::abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = 0;

    int x = x1;
    int y = y1;
    drawPixel(canvas,x,y,color);
    while ( x != x2 || y != y2) {
        int err2 = err + dy;
        if ( 2 * err2 >= dx) {
            y += sy;
            err = err2 - dx;
        }
        else {
            err = err2;
        }
        x += sx;
        drawPixel(canvas,x,y,color);
    }
    
     // TODO: реализовать целочисленный алгоритм Брезенхема
    // Использовать std::abs, переменные dx, dy, sx, sy, err
    // В цикле рисовать пиксель и изменять x1,y1 пока не дойдём до (x2,y2)
}

// ========== 6. Undo (оценка 4) ==========
void undo(Canvas& canvas) {
    if (!undoStack.empty()) {
        canvas = undoStack.top();
        undoStack.pop();
        

    }
    // TODO: если undoStack не пуст, то взять верхний элемент и присвоить canvas, затем удалить его
    // иначе ничего не делать
}

// ========== 7. Оттенки серого (оценка 5) ==========
void applyGrayscale(Canvas& canvas) {
    saveToUndo(canvas);
    for ( auto& row : canvas) {
        std::transform( row.begin(), row.end(), row.begin(), [](sf::Color c) {
            int gray = (c.r+c.g+c.b)/3;
            return sf::Color(gray,gray,gray);
        });
    }
    // TODO: применить к каждой строке
    // int gray = (c.r + c.g + c.b) / 3; return sf::Color(gray, gray, gray);

}

// ========== 8. Негатив (оценка 5) ==========
void applyNegative(Canvas& canvas) {
    saveToUndo(canvas);
    for ( auto& row : canvas ) {
        std::transform ( row.begin(), row.end(), row.begin(), [](sf::Color c) {
            return sf::Color(255 - c.r, 255 - c.g,255 - c.b);
        });
    }
    // TODO: аналогично, но для каждого компонента: 255 - c.r и т.д.
}

// ========== 9. Размытие (оценка 5) ==========
void applyBlur(Canvas& canvas) {
    saveToUndo(canvas);
    Canvas original = canvas;
    for ( int y = 1; y <= HEIGHT-2; y++) {
        for( int x = 1; x <= WIDTH-2; x++) {
            sf::Color c1 = original[y-1][x-1];
            sf::Color c2 = original[y-1][x];
            sf::Color c3 = original[y-1][x+1];
            sf::Color c4 = original[y][x-1];
            sf::Color c5 = original[y][x];
            sf::Color c6 = original[y][x+1];
            sf::Color c7 = original[y+1][x-1];
            sf::Color c8 = original[y+1][x];
            sf::Color c9 = original[y+1][x+1];

            int sumRed = (c1.r +c2.r + c3.r +c4.r +c5.r +c6.r + c7.r +c8.r + c9.r)/9;
            int sumGreen = (c1.g +c2.g + c3.g +c4.g +c5.g +c6.g + c7.g +c8.g + c9.g)/9;
            int sumBlue = (c1.b +c2.b + c3.b +c4.b +c5.b +c6.b + c7.b +c8.b + c9.b)/9;

            canvas[y][x] = sf::Color(sumRed, sumGreen, sumBlue);
        }
        
    }
    // TODO: создать копию Canvas original = canvas;
    // Для всех y от 1 до HEIGHT-2, x от 1 до WIDTH-2:
    //   просуммировать r,g,b всех 9 соседей из original, поделить на 9
    //   присвоить canvas[y][x] новый цвет
    // Границы не трогать (оставить как есть)
}

// ========== Вспомогательная отрисовка (уже готова) ==========
void renderToWindow(sf::RenderWindow& window, const Canvas& canvas) {
    static sf::Image image;
    static sf::Texture texture;
    static sf::Sprite sprite;
    
    image.create(WIDTH, HEIGHT);
    for (int y = 0; y < HEIGHT; ++y)
        for (int x = 0; x < WIDTH; ++x)
            image.setPixel(x, y, canvas[y][x]);
    
    texture.loadFromImage(image);
    texture.setSmooth(false);
    sprite.setTexture(texture);
    sprite.setScale(PIXEL_SIZE, PIXEL_SIZE);
    window.draw(sprite);
}