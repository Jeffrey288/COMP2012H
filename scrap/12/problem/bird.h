class Bird                    /* File: bird.h */
{
    ...
  public:
    void hatch_eggs();        // Birds lay eggs
    void lay_egg(int n);
    void spread_wings();      // Birds have wings
    void fly();               // Birds can fly
    int altitude() const;     // Return current altitude
};
