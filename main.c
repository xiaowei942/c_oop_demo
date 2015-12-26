#include <stdio.h>
#include "animal.h"
#include "penguin.h"
#include "swallow.h"
#include "bat.h"
#include "tiger.h"

void ClassInit();

int main()
{
    puts("start");
    ClassInit();

    ObjectPtr* penguin = Penguin_New();
    ObjectPtr* swallow = Swallow_New();
    ObjectPtr* bat = Bat_New();
    ObjectPtr* tiger = Tiger_New();
    //ObjectPtr* plane = Plane_New();

    ObjectPtr* animal[4] = {penguin, swallow, bat, tiger};

    /*
    IFly* flies[3] = {NULL};
    flies[0] = Swallow_AsIFly(swallow);
    flies[1] = Bat_AsIFly(bat);
    flies[2] = Plane_AsIFly(plane);
    */

    for (int i = 0; i < 4; ++i) {
        Animal_Eat(animal[i]);
        Animal_Breed(animal[i]);
    }

    /*
    for (int i = 0; i < 4; ++i) {
        IFly_Fly(flies[i]);
    }
    */

    Penguin_Delete(penguin);
    Swallow_Delete(swallow);
    Bat_Delete(bat);
    Tiger_Delete(tiger);
    //Plane_Delete(plane);

    puts("end");
    return 0;
}
