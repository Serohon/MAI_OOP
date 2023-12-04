#include "box_capacity.h"

int box_capacity(int length, int width, int height) {
    if (length < 0 or width < 0 or height < 0){
        return -1;
    }
    int boxLength = 16;
    int boxWidth = 16;
    int boxHeight = 16;
    int FeetToInch = 12;
    int numBoxesLength = length / boxLength * FeetToInch;
    int numBoxesWidth = width / boxWidth * FeetToInch; 
    int numBoxesHeight = height / boxHeight * FeetToInch;
    int totalBoxes = numBoxesLength * numBoxesWidth * numBoxesHeight;
    return totalBoxes;
}
