#include "TXLib.h"
#include "library.h"
#include <cmath>
#include <stdlib.h>
#include <ctime>


int main()
{
    int x, y; //переменные координаты(в цикле используются для машины)
    int numb_house_line, numb_house_column,x2,y2; // параметры отвечающие за дом
    int speed_bus,amon_car;//переменные для машины
    int numb_trees_line, numb_trees_column, h,color_trees,size_tree,x1,y1;//переменные для дерева
    int x3,y3,amon_obl; //облака
    int x4,y4;//переменные для дороги
    int start = 0;//остальные переменные


    cout <<  "Введите количество этажей дома: ";
    cin >> numb_house_column;
    cout <<  "\nВведите количество подъездов дома: ";
    cin  >> numb_house_line;
    cout << "\nВведите количество деревьев: " ;
    cin   >> numb_trees_line ;
    cout << "\nВведите количество облаков: " ;
    cin   >> amon_obl ;
    cout << "\nВведите количество машинок: " ;
    cin >> amon_car;//параметры введённые пользователями

    Limit(numb_house_line, numb_house_column,numb_trees_line,amon_obl,amon_car);


    txCreateWindow (1280,768);//создаём окн

    StartDraw();

    RECT stop = { 1044, 20,1260,100};
    RECT speedup = { 1044, 120,1260,200};
    RECT speeddown = { 1044, 220,1260,300};
    RECT high_bus_up = { 1044, 320,1260,400};
    RECT high_bus_down = { 1044, 420,1260,500};
    RECT start_prog = { 1044, 620,1260,700};
    RECT plustree = { 1044, 520,1144,600};
    RECT plusfloor = { 1160, 520,1260,600};
    RECT plusporch = { 1044, 620,1144,700};
    RECT plusoblako = { 1160, 620,1260,700};//области(кнопки)

    h = numb_trees_line % 8;
    numb_trees_column = numb_trees_line /8;//определяем количество "столбцов и строк" деревьев
    x=0;
    y=620;//начальные координаты машины

    x1=525;//начальные координаты деревьев
    y1=200;

    speed_bus = 0;

    srand(unsigned(time(0)));
    size_tree = rand() % 3;
    srand(unsigned(time(0)));// рандом для размера и цвета дерева
    color_trees = rand() % 3 ;



    for (int i=1; 1==1; x +=speed_bus)//начало цикла
    {


        if(txMouseButtons() & 1)
        {
            if (In (txMousePos(), start_prog))
            {
                start = 1;//программа начинается при нажатии по кнопке
            }
        }

        if(GetAsyncKeyState(VK_RETURN))
        {
            start = 1;//программа начинается при нажатии enter
        }

        if (start == 1)//проверка на старт цикла
        {

            txBegin();
            txSetFillColour(RGB(99, 90, 90));

            x3=20;//координаты для облаков
            y3=40;

            for (i=1; i<=amon_obl; i++)
            {
                Oblake(x3,y3);
                x3=x3+140;
            }

            x4=0;//координаты для дороги
            y4=688;

            road(x4, y4);//рисование дороги

            for (i=0; i<amon_car; i++)
            {
                paintcar (x+i*200,y);//рисование машины
            }

            x2=30;//переменные для дома
            y2=120;
            paintblock(x2, y2, numb_house_column, numb_house_line);//рисование дома







            for (int a=1; a<=numb_trees_column; a++)
            {
                for (int i=1; i<=8; i++)
                {
                    paintTrees(x1,y1,size_tree,color_trees);//рисование деревьев 1 фаза
                    x1=x1+65;
                }
                y1+=100;
                x1=525;
            }

            if (h <= 8 )
            {
                for (int i=1; i<=h; i++)
                {
                    paintTrees(x1,y1,size_tree,color_trees);//рисование деревьев 2 фаза
                    x1=x1+65;
                }
            }


            txSetColor (TX_BLACK);
            txSetFillColor (TX_BLACK);
            txRectangle(1024, 0,1280,768);//рисование панельки с кнопками
            txSetFillColor (TX_GRAY);
            txRectangle(1044, 20,1260,100);
            txRectangle(1044, 420,1260,500);
            txRectangle(1044, 320,1260,400);
            txSelectFont ("Comic Sans MS", 29);
            txTextOut (1045, 50, "Автобус останавливается");
            txRectangle(1044, 120,1260,200);
            txTextOut (1045, 150, "Автобус едет вправо");
            txRectangle(1044, 220,1260,300);
            txTextOut (1045, 250, "Автобус едет влево");
            txTextOut (1045, 350, "Автобус едет вверх");
            txTextOut (1045, 450, "Автобус едет вниз");//кнопки машинки

            txSelectFont ("Comic Sans MS", 20);
            txRectangle(1044, 520,1144,600);
            txTextOut (1045, 550, "+1 дерево");
            txRectangle(1160, 520,1260,600);
            txTextOut (1161, 550, "+1 этаж дома");
            txRectangle(1044, 620,1144,700);
            txTextOut (1045, 650, "+1 подъезд");
            txRectangle(1160, 620,1260,700);
            txTextOut (1161, 650, "+1 облако");//кнопки элементов


            if (x>=1024 + amon_car*120)
            {
                x=-120 - (amon_car+1) *120;//
            }

            if (x <= -120*(amon_car+1))
            {
                x=1144;
            }

            txSleep(0);

            if (speed_bus >=5)
            {
                speed_bus=5;//ограничение скорости вперёд
            }

            if (speed_bus <=-3)
            {
                speed_bus=-3;//ограничение скорости назад
            }

            if(GetAsyncKeyState('1'))
            {
                speed_bus=0;//остановка
            }
            if(GetAsyncKeyState(VK_ESCAPE))
            {
                break;//остановка программы
                return 0;
            }
            if(GetAsyncKeyState('3'))
            {
                y+=1;//кнопкой вверх
            }
            if(GetAsyncKeyState('4'))
            {
                y=y-1;//кнопкой вниз
            }

            if(y==558)
            {
                y=y+1;//ограничение скорости вверх
            }
            if(y==705)
            {
                y=y-1;//ограничение скорости вниз
            }
            road(0,768);//
            txSetFillColor (TX_GREEN);
            txSetColor (TX_GREEN);
            txRectangle(0, 558, 1024, 608);//

            if(txMouseButtons() & 1)
            {
                if (In (txMousePos(), stop))
                {
                    speed_bus=0;//остановка кнопкой
                }
            }

            txRectangle(1044, 120,1260,200);

            if(txMouseButtons() & 1)
            {
                if (In (txMousePos(), speedup))
                {
                    speed_bus=+3;//увеличение скорости кнопкой
                }
            }

            if(txMouseButtons() & 1)
            {
                if (In (txMousePos(), speeddown))
                {
                    speed_bus-=1;//уменьшение скорости кнопкой
                }
            }

            if(txMouseButtons() & 1)
            {
                if (In (txMousePos(), high_bus_up))
                {
                    y-=2;//движение кнопкой вверх
                }
            }

            if(txMouseButtons() & 1)
            {
                if (In (txMousePos(), high_bus_down))
                {
                    y+=2;//движение кнопкой вниз
                }
            }
            //RECT plustree = { 1044, 520,1144,600};
            //RECT plusfloor = { 1160, 520,1260,600};
            //RECT plusporch = { 1044, 620,1144,700};
            //RECT plusoblako = { 1160, 620,1260,700};//области(кнопки)
            if(txMouseButtons() & 1)
            {
                if (In (txMousePos(), plustree))
                {
                    if (numb_trees_line >=7)
                    {
                        numb_trees_line -=1;//+1 дерево
                    }
                    else {numb_trees_line +=1;}//+1 дерево
                }
            }
            if(txMouseButtons() & 1)
            {
                if (In (txMousePos(), plusfloor))
                {
                    if (numb_house_column >=6)
                    {
                        numb_house_column -=1;//+1 дерево
                    }
                    else {numb_house_column +=1;}//+1 дерево
                }
            }
            if(txMouseButtons() & 1)
            {
                if (In (txMousePos(), plusporch))
                {
                    if (numb_house_line >=7)
                    {
                        numb_house_line -=1;//+1 дерево
                    }
                    else {numb_house_line +=1;}//+1 дерево
                }
            }
            if(txMouseButtons() & 1)
            {
                if (In (txMousePos(), plusoblako))
                {
                    if (amon_obl >=7)
                    {
                        amon_obl -=1;//+1 дерево
                    }
                    else {amon_obl +=1;}//+1 дерево
                }
            }
            Limit(numb_house_line, numb_house_column,numb_trees_line,amon_obl,amon_car);
            h = numb_trees_line % 8;
            numb_trees_column = numb_trees_line /8;//определяем количество "столбцов и строк" деревьев
            x1=525;//меняем координаты для деревьев
            y1=200;
        }

    }
    return 0;
}
