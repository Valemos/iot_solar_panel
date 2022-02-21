#pragma once

class ConverterBuffer {

public:
    explicit ConverterBuffer(unsigned int max_size);
    ~ConverterBuffer();

    void SetValue(int value);
    int GetInt() const;

    void SetData(const uint8_t *data);
    const uint8_t *GetData() const;
    unsigned int Size() const;

private:
    uint8_t* buf_;
    unsigned int data_size_{0};
};


