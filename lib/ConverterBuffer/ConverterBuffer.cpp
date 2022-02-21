#include <Arduino.h>
#include "ConverterBuffer.h"

ConverterBuffer::ConverterBuffer(unsigned int max_size) : buf_(new uint8_t [max_size]){}

ConverterBuffer::~ConverterBuffer() {
    delete[] buf_;
}

void ConverterBuffer::SetValue(int value) {
    buf_[0] = value & 0xff;
    buf_[1] = value >> 8;
    data_size_ = 2;
}

int ConverterBuffer::GetInt() const {
    return buf_[1] << 8 | buf_[0];
}

const uint8_t *ConverterBuffer::GetData() const {
    return buf_;
}

void ConverterBuffer::SetData(const uint8_t *data) {

}

unsigned int ConverterBuffer::Size() const {
    return data_size_;
}
