#pragma once

#include <string.h>

class String {
public:
  String(void);
  String(const char* str);
  String(const String& other);
  ~String(void);

  const unsigned long length() const { return length_; }
  const char* c_str() const { return data_; }

  String& operator+=(const char* str) {
    if (str) {
      int len = strlen(str);
      char* r = new char[length_ + len + 1];
      memcpy(r, data_, length_);
      memcpy(r + length_, str, len);
      r[len + length_] = '\0';
      delete[] data_;
      data_ = r;
      length_ += len;
    }
    return *this;
  }

  String& operator+=(const String& other) {
    if (other.length_) {
      char* r = new char[length_ + other.length_ + 1];
      memcpy(r, data_, length_);
      memcpy(r + length_, other.data_, other.length_);
      r[other.length_ + length_] = '\0';
      delete[] data_;
      data_ = r;
      length_ += other.length_;
    }
    return *this;
  }

  String& operator=(const char* str) {
    if (str) {
      length_ = strlen(str);
      data_ = new char[length_ + 1];
      memcpy(data_, str, length_);
      data_[length_] = '\0';
    }
    return *this;
  }

  String& operator=(const String& other) {
    if (other.length_) {
      length_ = other.length_;
      delete[] data_;
      data_ = new char[length_ + 1];
      memcpy(data_, other.data_, length_);
      data_[length_] = '\0';
    }
    return *this;
  }


  // we need return its COPY not ref
  /*friend String&*/
  friend String operator+(const String& left, const String& right) {
    // Although below comments also successfully compile and run, but there is
    // a problem it would leak memory

    /*String* r = new String(left);
    *r += right;
    return *r;*/

    String r(left);
    r += right;
    return r;
  }

private:
  char* data_;
  unsigned long length_;
};

