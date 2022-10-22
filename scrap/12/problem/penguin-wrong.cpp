void find_food(Bird* bp) /* File: penguin-wrong.cpp */
{
    bp->fly();           // Visibility decreases with altitude
    double visibility = 10.0 / bp->altitude();
    ...
}
