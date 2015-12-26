
int main()
{
    Object* penguin = Penguin_New();
    Object* swallow = Swallow_New();
    Object* bat = Bat_New();
    Object* tiger = Tiger_New();
    Object* plane = Plane_New();

    Object* animal[4] = {penguin, swallow, bat, tiger};

    IFly* flies[3] = {NULL};
    flies[0] = Swallow_AsIFly(swallow);
    flies[1] = Bat_AsIFly(bat);
    flies[2] = Plane_AsIFly(plane);

    for (int i = 0; i < 4; ++i) {
        Animal_Eat(animal[i]);
        Animal_Breed(animal[i]);
    }

    for (int i = 0; i < 4; ++i) {
        IFly_Fly(flies[i]);
    }

    Penguin_Delete(penguin);
    Swallow_Delete(swallow);
    Bat_Delete(bat);
    Tiger_Delete(tiger);
    Plane_Delete(plane);

    return 0;
}
