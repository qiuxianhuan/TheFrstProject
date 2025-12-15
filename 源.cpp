#include<iostream>
#include<conio.h>//引用_getch()
#include<easyx.h>//easyx制作界面
#include<string>
#include<vector>
using namespace std;

void Interface_f(void);//第一个界面
void Interface_s(void);//第二个界面
void Inputbox(void);//实现输入
void Button(int, int, int, int);//登录的
void Button_ts();//试题维护的
void Background(void);//输出背景图
void Test(void);//试题测试的界面

class Inputtest
{
private:
	string A;
	string B;
	string C;
	string D;
	string answer;
	string question;
public:
	void InputQuestion()//这里也可以实现修改
	{
		cout << "请输入题目" << endl;
		cin >> question;
		settextstyle(25, 0, "楷体");
		outtextxy(80, 15, question.c_str());
		cout << "请输入选项A" << endl;
		cin >> A;
		outtextxy(30, 250, A.c_str());
		cout << "请输入选0项B" << endl;
		cin >> B;
		outtextxy(30, 300, B.c_str());
		cout << "请输入选项C" << endl;
		cin >> C;
		outtextxy(30, 350, C.c_str());
		cout << "请输入选项D" << endl;
		cin >> D;
		outtextxy(30, 400, D.c_str());
		cout << "请输入答案(请大写）" << endl;
		cin >> answer;
	}
		
};//试题输入

vector<Inputtest> bank;

void Background()
{
	IMAGE img;
	loadimage(&img, _T("D:/Users/123/source/repos/课设/resource/background.jpg"));
	putimage(0, 0, &img);
}

void Interface_f()
{   
	Background();
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	settextstyle(80, 0, "微软雅黑");
	outtextxy(270, 100, "Login");
	int x = 255;
	int y = 190;
	int width = 200;
	int hegith = 45;
	setfillcolor(RGB(192, 192, 192));
	solidrectangle(x, y, 455, 235);
	settextstyle(30, 0, "微软雅黑");
	settextcolor(BLACK);
	outtextxy(255, 200, "用户：");//255,190,455,235处
	setfillcolor(RGB(192, 192, 192));
	solidrectangle(x, 245, x + width, 245 + hegith);
	settextstyle(30, 0, "微软雅黑");
	settextcolor(BLACK);
	outtextxy(x, 250, "密码：");//在255,245,455,295处
	setfillcolor(RGB(192, 192, 192));
	solidrectangle(290, 300, 370, 350);
	settextstyle(40, 0, "微软雅黑");
	settextcolor(BLACK);
	outtextxy(300, 300, "登录");//这一部分在290,300,370,350处
}

void Interface_s()
{
	Background();
	int x = 255;
	int y = 100;
	int width = 200;
	int hegith = 45;
	setfillcolor(RGB(192, 192, 192));
	solidrectangle(x, y, 455, y+hegith);//
	settextstyle(30, 0, "楷体");
	settextcolor(BLACK);
	outtextxy(x + (width - textwidth("试题录入")) / 2, y + (hegith - textheight("试题录入")), "试题录入");//255,190,455,235处
	setfillcolor(RGB(192, 192, 192));
	solidrectangle(x, y + 10 + hegith, x + width, y + 2 * hegith + 10);//
	settextstyle(30, 0, "楷体");
	settextcolor(BLACK);
	outtextxy(x + (width - textwidth("试题维护")) / 2, y + 10 + hegith + (hegith - textheight("试题维护")), "试题维护");
	setfillcolor(RGB(192, 192, 192));
	solidrectangle(x, y + 2 * hegith + 20, x + width, y + 3 * hegith + 20);
	settextstyle(30, 0, "楷体");
	settextcolor(BLACK);
	outtextxy(x + (width - textwidth("测试")) / 2, y + 20 + 2 * hegith + (hegith - textheight("测试")), "测试");//这一部分在290,300,370,350处
	setfillcolor(RGB(192, 192, 192));
	solidrectangle(x, y + 3 * hegith + 30, x + width, y + 4 * hegith + 30);
	settextstyle(30, 0, "楷体");
	settextcolor(BLACK);
	outtextxy(x + (width - textwidth("查询")) / 2, y + 3 * hegith + 30 + (hegith - textheight("查询")), "查询");
}

void Inputbox()
{
	char input[15] = " ";//后面的核查也可以用这个，要初始化
	char input_[15] = " ";//后面的核查也可以用这个，要初始化
	int i = 0;//i是input的下标
	int j = 0;//j是input_的下标
	ExMessage msg = { 0 };
	bool need = true;
	int flag_n = 0;
	int flag_c = 0;
	while (true)
	{
		if (need)
		{
			cleardevice();
			Interface_f();
			settextstyle(25, 0, "微软雅黑");
			outtextxy(308, 203, input);
			outtextxy(308, 253, input_);//这是因为while回车后的输出要求（保证持续输出）
			need = false;
		}//这里是防止闪烁,一定加载界面，最后一次的输入会使need为flase
		if (peekmessage(&msg, EX_MOUSE))
		{
			if (msg.message == WM_LBUTTONDOWN)
			{
				if (msg.x >= 255 && msg.x <= 455 && msg.y >= 190 && msg.y <= 235)
				{
					while (true)
					{
						cleardevice();
						Interface_f();//这里是实现输入
						settextstyle(25, 0, ("微软雅黑"));
						outtextxy(308, 203, input);//在这里可输出最后一次输出
						outtextxy(308, 253, input_);
						char key = _getch();
						if (key == '\r')
						{
							flag_n++;
							break;
						}
						if (key == '\b' && i > 0)
						{
							input[--i] = '\0';
							need = true;
						}
						else if (key >= 32 && key <= 126 && i < 14)
						{
							input[i++] = key;
							input[i] = '\0';
							need = true;
						}
					}
				}
				else if (msg.x >= 255 && msg.x <= 455 && msg.y >= 245 && msg.y <= 295)
				{
					while (true)
					{
						cleardevice();
						Interface_f();//这里是实现输入
						settextstyle(25, 0, "微软雅黑");
						outtextxy(308, 203, input);
						outtextxy(308, 253, input_);
						char key = _getch();
						if (key == '\r')
						{
							flag_c++;
							break;
						}
						if (key == '\b' && j > 0)
						{
							input_[--j] = '\0';
							need = true;
						}
						else if (key >= 32 && key <= 126 && j < 14)
						{
							input_[j++] = key;
							input_[j] = '\0';
							need = true;
						}
					}
				}
			}
		}
		if (flag_n == 1 && flag_c == 1)
		{
			break;//完成两个输入才可返回,跳出while大循环的方法
		}
		Sleep(50);
	}
}

void Test()
{
	Background();
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	settextstyle(30, 0, "楷体");
	outtextxy(10, 10, "题目:");
	settextstyle(25, 0, "楷体");
	outtextxy(10, 250, "A:");
	outtextxy(10, 300, "B:");
	outtextxy(10, 350, "C:");
	outtextxy(10, 400, "D:");
}

void Button(int x,int y,int X,int Y)
{
	ExMessage msg;
	while (true)
	{
		if (peekmessage(&msg, EX_MOUSE));
		{
			while (msg.message == WM_LBUTTONDOWN)
			{
				if (msg.x >= x && msg.x <= X && msg.y >= y && msg.y <= Y)
				{
					Sleep(100);//不让按钮被点击多次！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！在这里加函数
					cleardevice();//加入第二个interface
					Interface_s();
					return;
				}
			}
		}
	}
}

void Button_ts()
{
	ExMessage msg;
	while (true)
	{
		if (peekmessage(&msg, EX_MOUSE));
		{
			if (msg.message == WM_LBUTTONDOWN)
			{
				if (msg.x >= 255 && msg.x <= 455 && msg.y >= 100 && msg.y <= 145)
				{
					Sleep(100);//不让按钮被点击多次！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！在这里加函数
					cleardevice();//加入第二个interface
					Test();
					return;
				}
				else if(msg.x >= 255 && msg.x <= 455 && msg.y >= 155 && msg.y <= 200)
				{
					Sleep(100);//不让按钮被点击多次！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！在这里加函数
					cleardevice();//加入第二个interface
					//Test();
					return;
				}
				else if (msg.x >= 255 && msg.x <= 455 && msg.y >= 210 && msg.y <= 255)
				{
					Sleep(100);//不让按钮被点击多次！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！在这里加函数
					cleardevice();//加入第二个interface
					//Test();
					return;
				}
				else if (msg.x >= 255 && msg.x <= 455 && msg.y >= 265 && msg.y <= 310)
				{
					Sleep(100);//不让按钮被点击多次！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！在这里加函数
					cleardevice();//加入第二个interface
					//Test();
					return;
				}
			}
		}
	}
}


int main()
{
	initgraph(680, 480, EX_SHOWCONSOLE);
	Inputbox();//方便后面
	//Interface_f();
	Button(290, 300, 370, 350);//必须先完成Input()函数才可执行下一个
	Button_ts();
	Inputtest t;
	t.InputQuestion();
	getchar();
	return 0;
}

