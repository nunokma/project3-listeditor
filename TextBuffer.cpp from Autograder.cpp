#include <cassert>
#include "TextBuffer.hpp"

TextBuffer::TextBuffer() : cursor(data.end()), row(1), column(0), index(0) {}

bool TextBuffer::forward() {
    if (cursor == data.end()) { return false; }
    else {
        if (*cursor == '\n') {
            row++;
            column = 0;
        }
        
        else { column++; }

        cursor++;
        index++;
        return true;
    }
}

int TextBuffer::compute_column() const {
    int c = 0;
    Iterator col = cursor;
    if (row == 1) {
        while (col != data.begin()) {
            c++;
            col--;
        }
    }
    else {
        col--;
        while (*col != '\n') {
            c++;
            col--;
        }
    }
    return c;
}

bool TextBuffer::backward() {
    if (cursor == data.begin()) { return false; }
    else {
        cursor--;
        if (*cursor == '\n') {
            row--;
            column = compute_column();
        }
        else {
            column--;
        }

        index--;
        return true;
    }
}

void TextBuffer::insert(char c) {
    data.insert(cursor, c);
    if (c == '\n') {
        row++;
        column = 0;
    }

    else { column++; }
    
    index++;
}

bool TextBuffer::remove() {
    if (cursor == data.end()) { return false; }
    else {
        cursor = data.erase(cursor);
        return true;
    }
}

void TextBuffer::move_to_row_start() {
    for (int c = column; c > 0; c--) {
        backward();
    }
}

void TextBuffer::move_to_row_end() {
    while (cursor != data.end() && *cursor != '\n') {
        forward();
    }
}

void TextBuffer::move_to_column(int new_column) {
    move_to_row_end();
    while (new_column < column) {
        backward();
    }
}

bool TextBuffer::up() {
    if (row == 1) {return false;}
    else {
        int current_column = column;
        for (int c = column + 1; c > 0; c--) {
            backward();
        }
        while (column > current_column) {
            backward();
        }
        return true;
    }
}

bool TextBuffer::down() {
    if (data.empty()) { return false; }
    int current_column = column;
    move_to_row_end();
    if (cursor == data.end()) {
        move_to_column(current_column);
        return false;
    }

    else {
        forward();
        while ( cursor != data.end() && column < current_column 
         && *cursor != '\n') { forward(); }
         return true;
    }
}

bool TextBuffer::is_at_end() const {
    return cursor == data.end();
}

char TextBuffer::data_at_cursor() const {
    assert(!is_at_end());
    return *cursor;
}

int TextBuffer::get_row() const {
    return row;
}

int TextBuffer::get_column() const {
    return column;
}

int TextBuffer::get_index() const {
    if (!is_at_end()) { return index; }
    else { return size(); }
}

int TextBuffer::size() const {
    return data.size();
}

std::string TextBuffer::stringify() const {
    return std::string(data.begin(), data.end());
}

