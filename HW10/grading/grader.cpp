#include <fstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include "dataset.h"
#include "nn.h"
using namespace std;

const string IDX = "Test Case ";
const string NAME = ": ";
const string LINE = "--------------------------------------------------";

void testing(NN&, dataset&);

int main()
{
    int cIdx = 0;
    cin >> cIdx;
    
    dataset data;
	data.load_dataset();

    NN nn("nn1.bin");

    if (cIdx == 1)
    {
        string name = "Task 1 print_statistic with TRAIN_IMAGE mode";
        cout << IDX << cIdx << NAME << name << endl
             << LINE << endl;
        data.print_statistic(TRAIN_IMAGE);
    }
    else if (cIdx == 2)
    {
        string name = "Task 1 print_statistic with TEST_IMAGE mode";
        cout << IDX << cIdx << NAME << name << endl
             << LINE << endl;
        data.print_statistic(TEST_IMAGE);
    }
    else if (cIdx == 3)
    {
        string name = "Task 2 testing a pretrained nn";
        cout << IDX << cIdx << NAME << name << endl
             << LINE << endl;
        testing(nn, data);
    }
    else if (cIdx == 4)
    {
        string name = "Task 3 remove_some_train_data with digit 3 and size 1300";
        cout << IDX << cIdx << NAME << name << endl
             << LINE << endl;
        data.remove_some_train_data(3, 1300);
	    data.print_statistic(TRAIN_IMAGE);
    }
    else if (cIdx == 5)
    {
        string name = "Task 4 print_image of the STL array type";
        cout << IDX << cIdx << NAME << name << endl
             << LINE << endl;
        
        array<uint8_t, PIXELS> img_ar = data.get_an_image(TRAIN_IMAGE, 3);
	    data.print_image(img_ar);
    }
    else if (cIdx == 6)
    {
        string name = "Task 5 print_image of the self-defined data type";
        cout << IDX << cIdx << NAME << name << endl
             << LINE << endl;
        array<uint8_t, PIXELS> img_ar = data.get_an_image(TRAIN_IMAGE, 3);
        img_dt img = data.convert_image_dt(img_ar);
	    data.print_image(img);
    }
    else if (cIdx == 7)
    {
        string name = "Task 6 convert_image_dt from array to self-defined data type";
        cout << IDX << cIdx << NAME << name << endl
             << LINE << endl;
        array<uint8_t, PIXELS> img_ar = data.get_an_image(TRAIN_IMAGE, 7);
        img_dt img = data.convert_image_dt(img_ar);
	    data.print_image(img);
    }
    else if (cIdx == 8)
    {
        string name = "Task 7 convert_image_dt from self-defined data type to array";
        cout << IDX << cIdx << NAME << name << endl
             << LINE << endl;
        array<uint8_t, PIXELS> img_ar = data.get_an_image(TRAIN_IMAGE, 7);
        img_dt img = data.convert_image_dt(img_ar);
        img_ar = data.convert_image_dt(img);	
	    data.print_image(img_ar);
    }
    else if (cIdx == 9)
    {
        string name = "Task 8 shift_image with dir = LEFT, p = 3, value = 1";
        cout << IDX << cIdx << NAME << name << endl
             << LINE << endl;
        array<uint8_t, PIXELS> img_ar = data.get_an_image(TRAIN_IMAGE, 3);
        cout << "Original image:" << endl;
        data.print_image(img_ar);
        img_dt img = data.convert_image_dt(img_ar);
        data.shift_image(img, LEFT, 3, 1);
        cout << "Manipulated image:" << endl;
	    data.print_image(img);
    }
    else if (cIdx == 10)
    {
        string name = "Task 8 shift_image with dir = RIGHT, p = 3, value = 1";
        cout << IDX << cIdx << NAME << name << endl
             << LINE << endl;
        array<uint8_t, PIXELS> img_ar = data.get_an_image(TRAIN_IMAGE, 3);
        cout << "Original image:" << endl;
        data.print_image(img_ar);
        img_dt img = data.convert_image_dt(img_ar);
        data.shift_image(img, RIGHT, 3, 1);
        cout << "Manipulated image:" << endl;
	    data.print_image(img);
    }
    else if (cIdx ==11)
    {
        string name = "Task 8 shift_image with dir = UP, p = 3, value = 1";
        cout << IDX << cIdx << NAME << name << endl
             << LINE << endl;
        array<uint8_t, PIXELS> img_ar = data.get_an_image(TRAIN_IMAGE, 3);
        cout << "Original image:" << endl;
        data.print_image(img_ar);
        img_dt img = data.convert_image_dt(img_ar);
        data.shift_image(img, UP, 3, 1);
        cout << "Manipulated image:" << endl;
	    data.print_image(img);
    }
    else if (cIdx ==12)
    {
        string name = "Task 8 shift_image with dir = DOWN, p = 3, value = 1";
        cout << IDX << cIdx << NAME << name << endl
             << LINE << endl;
        array<uint8_t, PIXELS> img_ar = data.get_an_image(TRAIN_IMAGE, 3);
        cout << "Original image:" << endl;
        data.print_image(img_ar);
        img_dt img = data.convert_image_dt(img_ar);
        data.shift_image(img, DOWN, 3, 1);
        cout << "Manipulated image:" << endl;
	    data.print_image(img);
    }
    else if (cIdx ==13)
    {
        string name = "Task 8 shift_image with dir = UPLEFT, p = 3, value = 1";
        cout << IDX << cIdx << NAME << name << endl
             << LINE << endl;
        array<uint8_t, PIXELS> img_ar = data.get_an_image(TRAIN_IMAGE, 3);
        cout << "Original image:" << endl;
        data.print_image(img_ar);
        img_dt img = data.convert_image_dt(img_ar);
        data.shift_image(img, UPLEFT, 3, 1);
        cout << "Manipulated image:" << endl;
	    data.print_image(img);
    }
    else if (cIdx ==14)
    {
        string name = "Task 8 shift_image with dir = UPRIGHT, p = 3, value = 1";
        cout << IDX << cIdx << NAME << name << endl
             << LINE << endl;
        array<uint8_t, PIXELS> img_ar = data.get_an_image(TRAIN_IMAGE, 3);
        cout << "Original image:" << endl;
        data.print_image(img_ar);
        img_dt img = data.convert_image_dt(img_ar);
        data.shift_image(img, UPRIGHT, 3, 1);
        cout << "Manipulated image:" << endl;
	    data.print_image(img);
    }
    else if (cIdx ==15)
    {
        string name = "Task 8 shift_image with dir = DOWNLEFT, p = 3, value = 1";
        cout << IDX << cIdx << NAME << name << endl
             << LINE << endl;
        array<uint8_t, PIXELS> img_ar = data.get_an_image(TRAIN_IMAGE, 3);
        cout << "Original image:" << endl;
        data.print_image(img_ar);
        img_dt img = data.convert_image_dt(img_ar);
        data.shift_image(img, DOWNLEFT, 3, 1);
        cout << "Manipulated image:" << endl;
	    data.print_image(img);
    }
    else if (cIdx ==16)
    {
        string name = "Task 8 shift_image with dir = DOWNRIGHT, p = 3, value = 1";
        cout << IDX << cIdx << NAME << name << endl
             << LINE << endl;
        array<uint8_t, PIXELS> img_ar = data.get_an_image(TRAIN_IMAGE, 3);
        cout << "Original image:" << endl;
        data.print_image(img_ar);
        img_dt img = data.convert_image_dt(img_ar);
        data.shift_image(img, DOWNRIGHT, 3, 1);
        cout << "Manipulated image:" << endl;
	    data.print_image(img);
    }
    else if (cIdx ==17)
    {
        string name = "Task 8 shift_image with dir = DOWNRIGHT, p = 0, value = 1";
        cout << IDX << cIdx << NAME << name << endl
             << LINE << endl;
        array<uint8_t, PIXELS> img_ar = data.get_an_image(TRAIN_IMAGE, 3);
        cout << "Original image:" << endl;
        data.print_image(img_ar);
        img_dt img = data.convert_image_dt(img_ar);
        data.shift_image(img, DOWNRIGHT, 0, 1);
        cout << "Manipulated image:" << endl;
	    data.print_image(img);
    }
    else if (cIdx == 18)
    {
        string name = "Task 9 resize_image with new_rows = 28 and new_cols = 28";
        cout << IDX << cIdx << NAME << name << endl
             << LINE << endl;
        array<uint8_t, PIXELS> img_ar = data.get_an_image(TRAIN_IMAGE, 3);
        cout << "Original image:" << endl;
        data.print_image(img_ar);
        img_dt img = data.convert_image_dt(img_ar);
        data.resize_image(img, 28, 28);
        cout << "Manipulated image:" << endl;
	    data.print_image(img);
    }
    else if (cIdx == 19)
    {
        string name = "Task 9 resize_image with new_rows = 29 and new_cols = 29";
        cout << IDX << cIdx << NAME << name << endl
             << LINE << endl;
        array<uint8_t, PIXELS> img_ar = data.get_an_image(TRAIN_IMAGE, 3);
        cout << "Original image:" << endl;
        data.print_image(img_ar);
        img_dt img = data.convert_image_dt(img_ar);
        data.resize_image(img, 29, 29);
        cout << "Manipulated image:" << endl;
	    data.print_image(img);
    }
    else if (cIdx == 20)
    {
        string name = "Task 9 resize_image with new_rows = 56 and new_cols = 56";
        cout << IDX << cIdx << NAME << name << endl
             << LINE << endl;
        array<uint8_t, PIXELS> img_ar = data.get_an_image(TRAIN_IMAGE, 3);
        cout << "Original image:" << endl;
        data.print_image(img_ar);
        img_dt img = data.convert_image_dt(img_ar);
        data.resize_image(img, 56, 56);
        cout << "Manipulated image:" << endl;
	    data.print_image(img);
    }
    else if (cIdx == 21)
    {
        string name = "Task 9 resize_image with new_rows = 27 and new_cols = 27";
        cout << IDX << cIdx << NAME << name << endl
             << LINE << endl;
        array<uint8_t, PIXELS> img_ar = data.get_an_image(TRAIN_IMAGE, 3);
        cout << "Original image:" << endl;
        data.print_image(img_ar);
        img_dt img = data.convert_image_dt(img_ar);
        data.resize_image(img, 27, 27);
        cout << "Manipulated image:" << endl;
	    data.print_image(img);
    }
    else if (cIdx == 22)
    {
        string name = "Task 9 resize_image with new_rows = 14 and new_cols = 14";
        cout << IDX << cIdx << NAME << name << endl
             << LINE << endl;
        array<uint8_t, PIXELS> img_ar = data.get_an_image(TRAIN_IMAGE, 3);
        cout << "Original image:" << endl;
        data.print_image(img_ar);
        img_dt img = data.convert_image_dt(img_ar);
        data.resize_image(img, 14, 14);
        cout << "Manipulated image:" << endl;
	    data.print_image(img);
    }
    else if (cIdx == 23)
    {
        string name = "Task 9 resize_image with new_rows = 1 and new_cols = 1";
        cout << IDX << cIdx << NAME << name << endl
             << LINE << endl;
        array<uint8_t, PIXELS> img_ar = data.get_an_image(TRAIN_IMAGE, 3);
        cout << "Original image:" << endl;
        data.print_image(img_ar);
        img_dt img = data.convert_image_dt(img_ar);
        data.resize_image(img, 1, 1);
        cout << "Manipulated image:" << endl;
	    data.print_image(img);
    }
    else if (cIdx == 24)
    {
        string name = "Task 10 crop_image with y0 = 0, x0 = 0, new_rows = 22 and new_cols = 24";
        cout << IDX << cIdx << NAME << name << endl
             << LINE << endl;
        array<uint8_t, PIXELS> img_ar = data.get_an_image(TRAIN_IMAGE, 3);
        cout << "Original image:" << endl;
        data.print_image(img_ar);
        img_dt img = data.convert_image_dt(img_ar);
        data.crop_image(img, 0, 0, 22, 24);
        cout << "Manipulated image:" << endl;
	    data.print_image(img);
    }
    else if (cIdx == 25)
    {
        string name = "Task 10 crop_image with y0 = 27, x0 = 1, new_rows = 1 and new_cols = 27";
        cout << IDX << cIdx << NAME << name << endl
             << LINE << endl;
        array<uint8_t, PIXELS> img_ar = data.get_an_image(TRAIN_IMAGE, 3);
        cout << "Original image:" << endl;
        data.print_image(img_ar);
        img_dt img = data.convert_image_dt(img_ar);
        data.crop_image(img, 27, 1, 1, 27);
        cout << "Manipulated image:" << endl;
	    data.print_image(img);
    }
    else if (cIdx == 26)
    {
        string name = "Task 10 crop_image with y0 = 1, x0 = 27, new_rows = 27 and new_cols = 1";
        cout << IDX << cIdx << NAME << name << endl
             << LINE << endl;
        array<uint8_t, PIXELS> img_ar = data.get_an_image(TRAIN_IMAGE, 3);
        cout << "Original image:" << endl;
        data.print_image(img_ar);
        img_dt img = data.convert_image_dt(img_ar);
        data.crop_image(img, 1, 27, 27, 1);
        cout << "Manipulated image:" << endl;
	    data.print_image(img);
    }
    else if (cIdx == 27)
    {
        string name = "Task 11 padding_image with top=0, down=0, left=0, right=0, value=1";
        cout << IDX << cIdx << NAME << name << endl
             << LINE << endl;
        array<uint8_t, PIXELS> img_ar = data.get_an_image(TRAIN_IMAGE, 3);
        cout << "Original image:" << endl;
        data.print_image(img_ar);
        img_dt img = data.convert_image_dt(img_ar);
        data.padding_image(img, 0, 0, 0, 0, 1);
        cout << "Manipulated image:" << endl;
	    data.print_image(img);
    }
    else if (cIdx == 28)
    {
        string name = "Task 11 padding_image with top=2, down=3, left=0, right=1, value=1";
        cout << IDX << cIdx << NAME << name << endl
             << LINE << endl;
        array<uint8_t, PIXELS> img_ar = data.get_an_image(TRAIN_IMAGE, 3);
        cout << "Original image:" << endl;
        data.print_image(img_ar);
        img_dt img = data.convert_image_dt(img_ar);
        data.padding_image(img, 2, 3, 0, 1, 1);
        cout << "Manipulated image:" << endl;
	    data.print_image(img);
    }
}
