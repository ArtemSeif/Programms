#include "TXLib.h"
#include "library.h"
#include <cmath>
#include <stdlib.h>
#include <ctime>


int main()
{
    int x, y; //���������� ����������(� ����� ������������ ��� ������)
    int numb_house_line, numb_house_column,x2,y2; // ��������� ���������� �� ���
    int speed_bus,amon_car;//���������� ��� ������
    int numb_trees_line, numb_trees_column, h,color_trees,size_tree,x1,y1;//���������� ��� ������
    int x3,y3,amon_obl; //������
    int x4,y4;//���������� ��� ������
    int start = 0;//��������� ����������


    cout <<  "������� ���������� ������ ����: ";
    cin >> numb_house_column;
    cout <<  "\n������� ���������� ��������� ����: ";
    cin  >> numb_house_line;
    cout << "\n������� ���������� ��������: " ;
    cin   >> numb_trees_line ;
    cout << "\n������� ���������� �������: " ;
    cin   >> amon_obl ;
    cout << "\n������� ���������� �������: " ;
    cin >> amon_car;//��������� �������� ��������������

    Limit(numb_house_line, numb_house_column,numb_trees_line,amon_obl,amon_car);


    txCreateWindow (1280,768);//������ ���

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
    RECT plusoblako = { 1160, 620,1260,700};//�������(������)

    h = numb_trees_line % 8;
    numb_trees_column = numb_trees_line /8;//���������� ���������� "�������� � �����" ��������
    x=0;
    y=620;//��������� ���������� ������

    x1=525;//��������� ���������� ��������
    y1=200;

    speed_bus = 0;

    srand(unsigned(time(0)));
    size_tree = rand() % 3;
    srand(unsigned(time(0)));// ������ ��� ������� � ����� ������
    color_trees = rand() % 3 ;



    for (int i=1; 1==1; x +=speed_bus)//������ �����
    {


        if(txMouseButtons() & 1)
        {
            if (In (txMousePos(), start_prog))
            {
                start = 1;//��������� ���������� ��� ������� �� ������
            }
        }

        if(GetAsyncKeyState(VK_RETURN))
        {
            start = 1;//��������� ���������� ��� ������� enter
        }

        if (start == 1)//�������� �� ����� �����
        {

            txBegin();
            txSetFillColour(RGB(99, 90, 90));

            x3=20;//���������� ��� �������
            y3=40;

            for (i=1; i<=amon_obl; i++)
            {
                Oblake(x3,y3);
                x3=x3+140;
            }

            x4=0;//���������� ��� ������
            y4=688;

            road(x4, y4);//��������� ������

            for (i=0; i<amon_car; i++)
            {
                paintcar (x+i*200,y);//��������� ������
            }

            x2=30;//���������� ��� ����
            y2=120;
            paintblock(x2, y2, numb_house_column, numb_house_line);//��������� ����







            for (int a=1; a<=numb_trees_column; a++)
            {
                for (int i=1; i<=8; i++)
                {
                    paintTrees(x1,y1,size_tree,color_trees);//��������� �������� 1 ����
                    x1=x1+65;
                }
                y1+=100;
                x1=525;
            }

            if (h <= 8 )
            {
                for (int i=1; i<=h; i++)
                {
                    paintTrees(x1,y1,size_tree,color_trees);//��������� �������� 2 ����
                    x1=x1+65;
                }
            }


            txSetColor (TX_BLACK);
            txSetFillColor (TX_BLACK);
            txRectangle(1024, 0,1280,768);//��������� �������� � ��������
            txSetFillColor (TX_GRAY);
            txRectangle(1044, 20,1260,100);
            txRectangle(1044, 420,1260,500);
            txRectangle(1044, 320,1260,400);
            txSelectFont ("Comic Sans MS", 29);
            txTextOut (1045, 50, "������� ���������������");
            txRectangle(1044, 120,1260,200);
            txTextOut (1045, 150, "������� ���� ������");
            txRectangle(1044, 220,1260,300);
            txTextOut (1045, 250, "������� ���� �����");
            txTextOut (1045, 350, "������� ���� �����");
            txTextOut (1045, 450, "������� ���� ����");//������ �������

            txSelectFont ("Comic Sans MS", 20);
            txRectangle(1044, 520,1144,600);
            txTextOut (1045, 550, "+1 ������");
            txRectangle(1160, 520,1260,600);
            txTextOut (1161, 550, "+1 ���� ����");
            txRectangle(1044, 620,1144,700);
            txTextOut (1045, 650, "+1 �������");
            txRectangle(1160, 620,1260,700);
            txTextOut (1161, 650, "+1 ������");//������ ���������


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
                speed_bus=5;//����������� �������� �����
            }

            if (speed_bus <=-3)
            {
                speed_bus=-3;//����������� �������� �����
            }

            if(GetAsyncKeyState('1'))
            {
                speed_bus=0;//���������
            }
            if(GetAsyncKeyState(VK_ESCAPE))
            {
                break;//��������� ���������
                return 0;
            }
            if(GetAsyncKeyState('3'))
            {
                y+=1;//������� �����
            }
            if(GetAsyncKeyState('4'))
            {
                y=y-1;//������� ����
            }

            if(y==558)
            {
                y=y+1;//����������� �������� �����
            }
            if(y==705)
            {
                y=y-1;//����������� �������� ����
            }
            road(0,768);//
            txSetFillColor (TX_GREEN);
            txSetColor (TX_GREEN);
            txRectangle(0, 558, 1024, 608);//

            if(txMouseButtons() & 1)
            {
                if (In (txMousePos(), stop))
                {
                    speed_bus=0;//��������� �������
                }
            }

            txRectangle(1044, 120,1260,200);

            if(txMouseButtons() & 1)
            {
                if (In (txMousePos(), speedup))
                {
                    speed_bus=+3;//���������� �������� �������
                }
            }

            if(txMouseButtons() & 1)
            {
                if (In (txMousePos(), speeddown))
                {
                    speed_bus-=1;//���������� �������� �������
                }
            }

            if(txMouseButtons() & 1)
            {
                if (In (txMousePos(), high_bus_up))
                {
                    y-=2;//�������� ������� �����
                }
            }

            if(txMouseButtons() & 1)
            {
                if (In (txMousePos(), high_bus_down))
                {
                    y+=2;//�������� ������� ����
                }
            }
            //RECT plustree = { 1044, 520,1144,600};
            //RECT plusfloor = { 1160, 520,1260,600};
            //RECT plusporch = { 1044, 620,1144,700};
            //RECT plusoblako = { 1160, 620,1260,700};//�������(������)
            if(txMouseButtons() & 1)
            {
                if (In (txMousePos(), plustree))
                {
                    if (numb_trees_line >=7)
                    {
                        numb_trees_line -=1;//+1 ������
                    }
                    else {numb_trees_line +=1;}//+1 ������
                }
            }
            if(txMouseButtons() & 1)
            {
                if (In (txMousePos(), plusfloor))
                {
                    if (numb_house_column >=6)
                    {
                        numb_house_column -=1;//+1 ������
                    }
                    else {numb_house_column +=1;}//+1 ������
                }
            }
            if(txMouseButtons() & 1)
            {
                if (In (txMousePos(), plusporch))
                {
                    if (numb_house_line >=7)
                    {
                        numb_house_line -=1;//+1 ������
                    }
                    else {numb_house_line +=1;}//+1 ������
                }
            }
            if(txMouseButtons() & 1)
            {
                if (In (txMousePos(), plusoblako))
                {
                    if (amon_obl >=7)
                    {
                        amon_obl -=1;//+1 ������
                    }
                    else {amon_obl +=1;}//+1 ������
                }
            }
            Limit(numb_house_line, numb_house_column,numb_trees_line,amon_obl,amon_car);
            h = numb_trees_line % 8;
            numb_trees_column = numb_trees_line /8;//���������� ���������� "�������� � �����" ��������
            x1=525;//������ ���������� ��� ��������
            y1=200;
        }

    }
    return 0;
}
