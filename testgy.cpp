#include "TXLib.h"
#include "library.h"
#include <cmath>
#include <stdlib.h>
#include <ctime>


int main()
{
    int x, y; //ïåðåìåííûå êîîðäèíàòû(â öèêëå èñïîëüçóþòñÿ äëÿ ìàøèíû)
    int numb_house_line, numb_house_column,x2,y2; // ïàðàìåòðû îòâå÷àþùèå çà äîì
    int speed_bus,amon_car;//ïåðåìåííûå äëÿ ìàøèíû
    int numb_trees_line, numb_trees_column, h,color_trees,size_tree,x1,y1;//ïåðåìåííûå äëÿ äåðåâà
    int x3,y3,amon_obl; //îáëàêà
    int x4,y4;//ïåðåìåííûå äëÿ äîðîãè
    int start = 0;//îñòàëüíûå ïåðåìåííûå


    cout <<  "Ââåäèòå êîëè÷åñòâî ýòàæåé äîìà: ";
    cin >> numb_house_column;
    cout <<  "\nÂâåäèòå êîëè÷åñòâî ïîäúåçäîâ äîìà: ";
    cin  >> numb_house_line;
    cout << "\nÂâåäèòå êîëè÷åñòâî äåðåâüåâ: " ;
    cin   >> numb_trees_line ;
    cout << "\nÂâåäèòå êîëè÷åñòâî îáëàêîâ: " ;
    cin   >> amon_obl ;
    cout << "\nÂâåäèòå êîëè÷åñòâî ìàøèíîê: " ;
    cin >> amon_car;//ïàðàìåòðû ââåä¸ííûå ïîëüçîâàòåëÿìè

    Limit(numb_house_line, numb_house_column,numb_trees_line,amon_obl,amon_car);


    txCreateWindow (1280,768);//ñîçäà¸ì îêí

    StartDraw();

    RECT stop = { 1044, 20,1260,100};
    RECT speedup = { 1044, 120,1260,200};
    RECT speeddown = { 1044, 220,1260,300};
    RECT high_bus_up = { 1044, 320,1260,400};
    RECT high_bus_down = { 1044, 420,1260,500};
    RECT start_prog = { 1044, 620,1260,700};
    RECT plustree = { 1044, 520,1144,600};
    RECT plusfloor = { 1160, 520,1260,600};
    RECT plusporch = ìàøèí

    x1=525;//íà÷àëüíûå êîîðäèíàòû äåðåâüåâ
    y1=200;

    speed_bus = 0;

    srand(unsigned(time(0)));
    size_tree = rand() % 3;
    srand(unsigned(time(0)));// ðàíäîì äëÿ ðàçìåðà è öâåòà äåðåâà
    color_trees = rand() % 3 ;



    for (int i=1; 1==1; x +=speed_bus)//íà÷àëî öèêëà
    {


        if(txMouseButtons() & 1)
        {
            if (In (txMousePos(), start_prog))
            {
                start = 1;//ïðîãðàììà íà÷èíàåòñÿ ïðè íàæàòèè ïî êíîïêå
            }
        }

        if(GetAsyncKeyState(VK_RETURN))
        {
            start = 1;//ïðîãðàììà íà÷èíàåòñÿ ïðè íàæàòèè enter
        }

        if (start == 1)//ïðîâåðêà íà ñòàðò öèêëà
        {

            txBegin();
            txSetFillColour(RGB(99, 90, 90));

            x3=20;//êîîðäèíàòû äëÿ îáëàêîâ
            y3=40;

            for (i=1; i<=amon_obl; i++)
            {
                Oblake(x3,y3);
                x3=x3+140;
            }

            x4=0;//êîîðäèíàòû äëÿ äîðîãè
            y4=688;

            road(x4, y4);//ðèñîâàíèå äîðîãè

            for (i=0; i<amon_car; i++)
            {
                paintcar (x+i*200,y);//ðèñîâàíèå ìàøèíû
            }

            x2=30;//ïåðåìåííûå äëÿ äîìà
            y2=120;
            paintblock(x2, y2, numb_house_column, numb_house_line);//ðèñîâàíèå äîìà







            for (int a=1; a<=numb_trees_column; a++)
            {
                for (int i=1; i<=8; i++)
                {
                    paintTrees(x1,y1,size_tree,color_trees);//ðèñîâàíèå äåðåâüåâ 1 ôàçà
                    x1=x1+65;
                }
                y1+=100;
                x1=525;
            }

            if (h <= 8 )
            {
                for (int i=1; i<=h; i++)
                {
                    paintTrees(x1,y1,size_tree,color_trees);//ðèñîâàíèå äåðåâüåâ 2 ôàçà
                    x1=x1+65;
                }
            }


            txSetColor (TX_BLACK);
            txSetFillColor (TX_BLACK);
            txRectangle(1024, 0,1280,768);//ðèñîâàíèå ïàíåëüêè ñ êíîïêàìè
            txSetFillColor (TX_GRAY);
            txRectangle(1044, 20,1260,100);
            txRectangle(1044, 420,1260,500);
            txRectangle(1044, 320,1260,400);
            txSelectFont ("Comic Sans MS", 29);
            txTextOut (1045, 50, "Àâòîáóñ îñòàíàâëèâàåòñÿ");
            txRectangle(1044, 120,1260,200);
            txTextOut (1045, 150, "Àâòîáóñ åäåò âïðàâî");
            txRectangle(1044, 220,1260,300);
            txTextOut (1045, 250, "Àâòîáóñ åäåò âëåâî");
            txTextOut (1045, 350, "Àâòîáóñ åäåò ââåðõ");
            txTextOut (1045, 450, "Àâòîáóñ åäåò âíèç");//êíîïêè ìàøèíêè

            txSelectFont ("Comic Sans MS", 20);
            txRectangle(1044, 520,1144,600);
            txTextOut (1045, 550, "+1 äåðåâî");
            txRectangle(1160, 520,1260,600);
            txTextOut (1161, 550, "+1 ýòàæ äîìà");
            txRectangle(1044, 620,1144,700);
            txTextOut (1045, 650, "+1 ïîäúåçä");
            txRectangle(1160, 620,1260,700);
            txTextOut (1161, 650, "+1 îáëàêî");//êíîïêè ýëåìåíòîâ


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
                speed_bus=5;//îãðàíè÷åíèå ñêîðîñòè âïåð¸ä
            }

            if (speed_bus <=-3)
            {
                speed_bus=-3;//îãðàíè÷åíèå ñêîðîñòè íàçàä
            }

            if(GetAsyncKeyState('1'))
            {
                speed_bus=0;//îñòàíîâêà
            }
            if(GetAsyncKeyState(VK_ESCAPE))
            {
                break;//îñòàíîâêà ïðîãðàììû
                return 0;
            }
            if(GetAsyncKeyState('3'))
            {
                y+=1;//êíîïêîé ââåðõ
            }
            if(GetAsyncKeyState('4'))
            {
                y=y-1;//êíîïêîé âíèç
            }

            if(y==558)
            {
                y=y+1;//îãðàíè÷åíèå ñêîðîñòè ââåðõ
            }
            if(y==705)
            {
                y=y-1;//îãðàíè÷åíèå ñêîðîñòè âíèç
            }
            road(0,768);//
            txSetFillColor (TX_GREEN);
            txSetColor (TX_GREEN);
            txRectangle(0, 558, 1024, 608);//

            if(txMouseButtons() & 1)
            {
                if (In (txMousePos(), stop))
                {
                    speed_bus=0;//îñòàíîâêà êíîïêîé
                }
            }

            txRectangle(1044, 120,1260,200);

            if(txMouseButtons() & 1)
            {
                if (In (txMousePos(), speedup))
                {
                    speed_bus=+3;//óâåëè÷åíèå ñêîðîñòè êíîïêîé
                }
            }

            if(txMouseButtons() & 1)
            {
                if (In (txMousePos(), speeddown))
                {
                    speed_bus-=1;//óìåíüøåíèå ñêîðîñòè êíîïêîé
                }
            }

            if(txMouseButtons() & 1)
            {
                if (In (txMousePos(), high_bus_up))
                {
                    y-=2;//äâèæåíèå êíîïêîé ââåðõ
                }
            }

            if(txMouseButtons() & 1)
            {
                if (In (txMousePos(), high_bus_down))
                {
                    y+=2;//äâèæåíèå êíîïêîé âíèç
                }
            }
            //RECT plustree = { 1044, 520,1144,600};
            //RECT plusfloor = { 1160, 520,1260,600};
            //RECT plusporch = { 1044, 620,1144,700};
            //RECT plusoblako = { 1160, 620,1260,700};//îáëàñòè(êíîïêè)
            if(txMouseButtons() & 1)
            {
                if (In (txMousePos(), plustree))
                {
                    if (numb_trees_line >=7)
                    {
                        numb_trees_line -=1;//+1 äåðåâî
                    }
                    else {numb_trees_line +=1;}//+1 äåðåâî
                }
            }
            if(txMouseButtons() & 1)
            {
                if (In (txMousePos(), plusfloor))
                {
                    if (numb_house_column >=6)
                    {
                        numb_house_column -=1;//+1 äåðåâî
                    }
                    else {numb_house_column +=1;}//+1 äåðåâî
                }
            }
            if(txMouseButtons() & 1)
            {
                if (In (txMousePos(), plusporch))
                {
                    if (numb_house_line >=7)
                    {
                        numb_house_line -=1;//+1 äåðåâî
                    }
                    else {numb_house_line +=1;}//+1 äåðåâî
                }
            }
            if(txMouseButtons() & 1)
            {
                if (In (txMousePos(), plusoblako))
                {
                    if (amon_obl >=7)
                    {
                        amon_obl -=1;//+1 äåðåâî
                    }
                    else {amon_obl +=1;}//+1 äåðåâî
                }
            }
            Limit(numb_house_line, numb_house_column,numb_trees_line,amon_obl,amon_car);
            h = numb_trees_line % 8;
            numb_trees_column = numb_trees_line /8;//îïðåäåëÿåì êîëè÷åñòâî "ñòîëáöîâ è ñòðîê" äåðåâüåâ
            x1=525;//ìåíÿåì êîîðäèíàòû äëÿ äåðåâüåâ
            y1=200;
        }

    }
    return 0;
}
