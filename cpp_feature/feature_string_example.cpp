#include "feature_string_example.h"


String::String(void) {
  data_ = new char[1];
  data_[0] = '\0';
  length_ = 0;
}

String::String(const char* str) {
  if (str == NULL) {
    data_ = new char[1];
    data_[0] = '\0';
    length_ = 0;
  } else {
    length_ = strlen(str);
    data_ = new char[length_ + 1];
    memcpy(data_, str, length_);
    data_[length_] = '\0';
  }
}

String::String(const String& other) {
  if (other.length_) {
    /*if (length_)
      delete[] data_;*/
    data_ = new char[other.length_ + 1];
    memcpy(data_, other.data_, other.length_);
    data_[other.length_] = '\0';
    length_ = other.length_;
  } else {
    data_ = new char[1];
    data_[0] = '\0';
    length_ = 0;
  }
}

String::~String(void) {
  delete[] data_;
  length_ = 0;
}


