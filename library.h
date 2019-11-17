void car(int x, int y)
{
    txSetColour(TX_BLACK);
    txSetFillColour(RGB(247, 15, 15));
    POINT ostov[7] = {{x, y}, {x-20, y-12}, {x-55, y-12}, {x-75, y}, {x-95, y}, {x-95, y+17}, {x, y+17}};
    txPolygon (ostov, 7);
    POINT dver[5] = {{x-68, y}, {x-52, y-10}, {x-40, y-10}, {x-40, y+15}, {x-68, y+15}};
    txPolygon (dver, 5);
    txSetColour(RGB(16, 176, 235), 1);
    txSetFillColour (RGB(16, 176, 235));
    POINT stecl[4] = {{x-64, y}, {x-49, y-8}, {x-43, y-8}, {x-43, y}};
    txPolygon (stecl, 4);
    POINT stecl2[4] = {{x-37, y-8}, {x-20, y-8}, {x-5, y}, {x-37, y}};
    txPolygon (stecl2, 4);
    txSetColour(TX_BLACK);
    txSetFillColour(TX_BLACK);
    txCircle(x-20, y+17, 10);
    txCircle(x-75, y+17, 10);
    txSetFillColour(TX_WHITE);
    txCircle (x-20, y+17, 7);
    txCircle (x-75, y+17, 7);
    txSetFillColour(RGB(234, 255, 0));
    txRectangle(x-95, y+4, x-90, y+10);
}
void paintblock(int x, int y, int numb_house_column, int numb_house_line)
{
    for (int i=1; i<=numb_house_column; i++)
    {
        for (int z=1; z<=numb_house_line; z++)
        {
            txSetFillColor (TX_ORANGE);
            txSetColor (TX_BLACK);
            txRectangle(x, y, x+60, y+70);
            txSetFillColor (TX_LIGHTBLUE);
            txRectangle(x+20, y+15, x+40, y+45);
            txLine(x+30, y+15, x+30, y+45);
            txLine(x+20, y+30, x+30, y+30);
            x+=60;
        }
        x=30;
        y+=70;
    }
}
void paintcar(int x, int y)
{
    txSetColour (TX_BLACK);
    txSetFillColour (TX_ORANGE);
    txRectangle (x,y,x+120,y+50);
    txSetFillColour(RGB(235, 111, 16));
    txRectangle (x+73,y+15,x+89,y+50);
    txSetFillColour (RGB(16, 176, 235));
    txRectangle (x+75,y+17,x+87,y+31);
    txSetFillColour(TX_BLACK);
    txCircle (x+20, y+50, 13);
    txCircle (x+100, y+50, 13);
    txSetFillColour(TX_WHITE);
    txCircle (x+20, y+50, 7);
    txCircle (x+100, y+50, 7);
    txSetFillColour (RGB(16, 176, 235));
    txRectangle (x+5,y+10,x+35,y+33);
    txRectangle (x+40,y+10,x+70,y+33);
    txRectangle (x+110,y+10,x+120,y+33);
    txSetFillColour(RGB(234, 255, 0));
    txRectangle (x+115,y+40,x+120,y+45);
    txSetColour(TX_BLACK);
}
void paintTrees(int x, int y,int size_tree, int color_trees)
{
    switch(color_trees)
    {
    case 0:
        txSetColor (TX_LIGHTGREEN);
        txSetFillColor (TX_LIGHTGREEN);
        break;
    case 1:
        txSetColor (TX_RED);
        txSetFillColor (TX_RED);
        break;
    case 2:
        txSetColor (TX_YELLOW);
        txSetFillColor (TX_YELLOW);
        break;

    }
    txCircle (x, y, 15*size_tree);
    size_tree = rand() % 3;
    txCircle (x+7, y+5, 15*size_tree);
    size_tree = rand() % 3;
    txCircle (x-7, y+10, 15*size_tree);
    txSetColor (TX_BROWN, 5);
    txLine(x, y, x, y+50);
    txLine(x, y+20, x+10, y+5);
    txLine(x, y+30, x-10, y+10);
}
void road (int x, int y)
{
    txSetFillColour(RGB(99, 90, 90));
    txSetColour(RGB(99, 90, 90));
    txRectangle(0, 608, 1024, 768);
    txSetFillColour(TX_WHITE);
    for (int i=1; i<=7; i++)
    {
        txRectangle (x, y, x+120, y+10);
        x+=145;
    }
}
void Oblake(int x, int y)
{
    txSetFillColour(TX_WHITE);
    txSetColor(TX_WHITE);
    txCircle (x+35, y+15, 22);
    txCircle (x-5, y+12.5, 17);
    txCircle (x-40, y+13.5, 15);
    txCircle (x+15, y, 30);
}
void Limit(int numb_house_line, int numb_house_column, int numb_trees_line, int amon_obl, int amon_car)
{
                if (numb_house_line >=7)
            {
                numb_house_line =7;
            }
            if (numb_house_column >=6)
            {
                numb_house_column = 6;
            }
            if (numb_trees_line >32)
            {
                numb_trees_line =32;
            }
            if (amon_obl >7)
            {
                amon_obl =7;
            }
            if (amon_car >3)
            {
                amon_car =3;// ограничения
            }
                if (numb_house_line <= 1)
            {
                numb_house_line =1;
            }
            if (numb_house_column <=1)
            {
                numb_house_column = 1;
            }
            if (numb_trees_line <= 1)
            {
                numb_trees_line =1;
            }
            if (amon_obl <= 1)
            {
                amon_obl =1;
            }
            if (amon_car <= 1)
            {
                amon_car =1;// ограничения 2
            }
}
void StartDraw ()
{
    txSetFillColor (TX_LIGHTBLUE);
    txSetColor (TX_LIGHTBLUE);
    txRectangle(0, 0, 1024, 200);//рисуем небо

    txSetFillColor (TX_GREEN);
    txSetColor (TX_GREEN);
    txRectangle(0, 200, 1024, 768);//рисуем траву

    txSetFillColor (TX_YELLOW);
    txCircle(905,100, 70);//Солнце

    txSetFillColor (TX_GRAY);
    txRectangle(1044, 620,1260,700);
    txTextOut (1045, 650, "СТАРТ");//рисуется кнопка старт
}

