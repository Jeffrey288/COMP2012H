class Penguin : public Bird /* File: penguin2.h */
{
    ...
  public:
    ...
    void swim();
    void catch_fish();
    void fly() { }                     // Penguin can't fly
    int altitude() const { return 0; } // Always zero
};
