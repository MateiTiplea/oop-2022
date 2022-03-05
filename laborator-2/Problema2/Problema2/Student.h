#pragma once

class Student {
  private:
    char name[20];
    float Math;
    float English;
    float History;
    float Average;

  public:
    Student();
    void SetName(const char* name);
    const char* GetName() const;
    bool SetMath(const float Math);
    const float GetMath() const;
    bool SetEnglish(const float English);
    const float GetEnglish() const;
    bool SetHistory(const float History);
    const float GetHistory() const;
    const float Avg();
};