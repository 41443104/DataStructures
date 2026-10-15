#include<iostream>
#include <string>
using namespace std;
class GameCharacter
{
public:
	string name;
	int hp;
	int level;
	GameCharacter(string n, int h, int l)
	{
		name = n;// 將 n 存入 name
		hp = h;// 將 h 存入 hp
		level = l;// 將 l 存入 level
	}
	// 受到傷害
	void damage(int value)
	{
		int h = hp - value;
		if (h <= 0)
		{
			hp = 0;
		}
		else
		{
			hp = h;
		}
		cout <<"血量:" << hp << endl;
	}
	// 回復生命值
	void heal(int value)
	{
		int h = hp + value;
		if (h >=100)
		{
			hp = 100;
		}
		else
		{
			hp = h;
		}
		cout << "血量:" << hp << endl;
	}
	// 升級
	void levelUp()
	{
		level++;
		hp = 100;
		cout << "角色升級!";
	}
	// 顯示角色資料
	void show()
	{
		cout << "Name: " << name << endl;
		cout << "HP: " << hp << endl;
		cout << "Level: " << level << endl;
	}
};
int main()
{
		string n;
		int l, h;
		cout << "輸入角色名稱:";
		cin >> n;
		cout << "輸入血量:";
		cin >> h;
		cout << "輸入等級:";
		cin >> l;
		GameCharacter p1(n, h, l);
	int c;
	do
	{
		cout << endl;
		cout << "\n========== 選單 ==========" << endl;
		cout << "1. 扣血" << endl;
		cout << "2. 回血" << endl;
		cout << "3. 升級" << endl;
		cout << "4. Show角色資料" << endl;
		cout << "0. 結束程式" << endl;
		cout << "請選擇: ";
		cin >> c;
		if (c == 1)
		{
			int value;
			cout << "輸入傷害值:";
			cin >> value;
			p1.damage(value);
		}
		else if (c == 2)
		{
			int value;
			cout << "輸入回血量:";
			cin >> value;
			p1.heal(value);
		}
		else if (c == 3)
		{ 
			p1.levelUp();
			cout << "成功!";
		}
		else if (c == 4)
		{
			p1.show();
		}
		else if (c == 0){cout << "結束";	}
	}
	while (c != 0);
	return 0;
}