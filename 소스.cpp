#include <bangtal.h>
#include <iostream>
#include <ctime>

using namespace bangtal;
using namespace std;

int main()
{
	srand((unsigned int)time(NULL));
	time_t start_time;

	setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
	setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);

	auto scene1 = Scene::create("슬라이드퍼즐 1", "images/배경.jpg");
	auto scene2 = Scene::create("슬라이드퍼즐 2", "images/배경.jpg");
	auto scene3 = Scene::create("슬라이드퍼즐 3", "images/배경.jpg");

	ObjectPtr Gameboard1[25];
	ObjectPtr Initboard1[25];
	ObjectPtr Gameboard2[25];
	ObjectPtr Initboard2[25];
	ObjectPtr Gameboard3[25];
	ObjectPtr Initboard3[25];

	int blank = 24;
	for (int i = 0; i < 25; i++) {
		string filename = "images/1-" + to_string(i + 1) + ".jpg";		
		cout << filename << endl;

		Gameboard1[i] = Object::create(filename, scene1, 256 * (i % 5), 576 - 144 * (i / 5));
		Initboard1[i] = Gameboard1[i];
		Gameboard1[i]->setOnMouseCallback([&](ObjectPtr object, int, int, MouseAction)->bool {
			int j;
			for (j = 0; j < 25; j++) {
				if (Gameboard1[j] == object)
					break;
			}
			cout << j << endl;

			if ((j % 5 > 0 && j - 1 == blank) ||
				(j % 5 < 4 && j + 1 == blank) ||
				(j > 4 && j - 5 == blank) ||
				(j < 20 && j + 5 == blank))
			{
				cout << "move" << blank << "<->" << j << endl;
				Gameboard1[j]->locate(scene1, 256 * (blank % 5), 576 - 144 * (blank / 5));
				Gameboard1[blank]->locate(scene1, 256 * (j % 5), 576 - 144 * (j / 5));

				Gameboard1[j] = Gameboard1[blank];
				Gameboard1[blank] = object;
				blank = j;

				int k;
				for (k = 0; k < 25; k++) {
					if (Gameboard1[k] != Initboard1[k]) break;
				}
				if (k == 25) {
					auto end_time = time(NULL);
					cout << difftime(end_time, start_time) << endl;

					string buf = to_string(difftime(end_time, start_time))
						+ "초 걸렸습니다.";
					showMessage(buf.c_str());
				}
			}
			return true;
		});

	}
	Gameboard1[blank]->hide();

	for (int i = 0; i < 25; i++) {
		string filename = "images/2-" + to_string(i + 1) + ".jpg";
		cout << filename << endl;

		Gameboard2[i] = Object::create(filename, scene2, 256 * (i % 5), 576 - 144 * (i / 5));
		Initboard2[i] = Gameboard2[i];
		Gameboard2[i]->setOnMouseCallback([&](ObjectPtr object, int, int, MouseAction)->bool {
			int j;
			for (j = 0; j < 25; j++) {
				if (Gameboard2[j] == object)
					break;
			}
			cout << j << endl;

			if ((j % 5 > 0 && j - 1 == blank) ||
				(j % 5 < 4 && j + 1 == blank) ||
				(j > 4 && j - 5 == blank) ||
				(j < 20 && j + 5 == blank))
			{
				cout << "move" << blank << "<->" << j << endl;
				Gameboard2[j]->locate(scene2, 256 * (blank % 5), 576 - 144 * (blank / 5));
				Gameboard2[blank]->locate(scene2, 256 * (j % 5), 576 - 144 * (j / 5));

				Gameboard2[j] = Gameboard2[blank];
				Gameboard2[blank] = object;
				blank = j;

				int k;
				for (k = 0; k < 25; k++) {
					if (Gameboard2[k] != Initboard2[k]) break;
				}
				if (k == 25) {
					auto end_time = time(NULL);
					cout << difftime(end_time, start_time) << endl;

					string buf = to_string(difftime(end_time, start_time))
						+ "초 걸렸습니다.";
					showMessage(buf.c_str());
				}
			}
			return true;
			});

	}
	Gameboard2[blank]->hide();

	for (int i = 0; i < 25; i++) {
		string filename = "images/3-" + to_string(i + 1) + ".jpg";
		cout << filename << endl;

		Gameboard3[i] = Object::create(filename, scene3, 256 * (i % 5), 576 - 144 * (i / 5));
		Initboard3[i] = Gameboard3[i];
		Gameboard3[i]->setOnMouseCallback([&](ObjectPtr object, int, int, MouseAction)->bool {
			int j;
			for (j = 0; j < 25; j++) {
				if (Gameboard3[j] == object)
					break;
			}
			cout << j << endl;

			if ((j % 5 > 0 && j - 1 == blank) ||
				(j % 5 < 4 && j + 1 == blank) ||
				(j > 4 && j - 5 == blank) ||
				(j < 20 && j + 5 == blank))
			{
				cout << "move" << blank << "<->" << j << endl;
				Gameboard3[j]->locate(scene3, 256 * (blank % 5), 576 - 144 * (blank / 5));
				Gameboard3[blank]->locate(scene3, 256 * (j % 5), 576 - 144 * (j / 5));

				Gameboard3[j] = Gameboard3[blank];
				Gameboard3[blank] = object;
				blank = j;

				int k;
				for (k = 0; k < 25; k++) {
					if (Gameboard3[k] != Initboard3[k]) break;
				}
				if (k == 25) {
					auto end_time = time(NULL);
					cout << difftime(end_time, start_time) << endl;

					string buf = to_string(difftime(end_time, start_time))
						+ "초 걸렸습니다.";
					showMessage(buf.c_str());
				}
			}
			return true;
			});

	}
	Gameboard3[blank]->hide();

	auto count = 0;
	auto timer1 = Timer::create(0.1f);
	timer1->setOnTimerCallback([&](TimerPtr t)->bool {
		cout << "timeout" << count << endl;

		int j = 0;
		switch (rand() % 4) {
		case 0: j = blank - 1; break;
		case 1: j = blank + 1; break;
		case 2: j = blank - 5; break;
		case 3: j = blank + 5; break;
		}
		if (j > 0 && j < 25 && ((j % 5 > 0 && j - 1 == blank) ||
			(j % 5 < 4 && j + 1 == blank) ||
			(j > 4 && j - 5 == blank) ||
			(j < 20 && j + 5 == blank)))
		{
			cout << "move" << blank << "<->" << j << endl;
				Gameboard1[j]->locate(scene1, 256 * (blank % 5), 576 - 144 * (blank / 5));
				Gameboard1[blank]->locate(scene1, 256 * (j % 5), 576 - 144 * (j / 5));

				auto s1 = Gameboard1[j];
				Gameboard1[j] = Gameboard1[blank];
				Gameboard1[blank] = s1;
				blank = j;

		}

		count++;
		if (count < 100) {
			t->set(0.1f);
			t->start();
		}
		return true;
	});

	auto timer2 = Timer::create(0.1f);
	timer2->setOnTimerCallback([&](TimerPtr t)->bool {
		cout << "timeout" << count << endl;

		int j = 0;
		switch (rand() % 4) {
		case 0: j = blank - 1; break;
		case 1: j = blank + 1; break;
		case 2: j = blank - 5; break;
		case 3: j = blank + 5; break;
		}
		if (j > 0 && j < 25 && ((j % 5 > 0 && j - 1 == blank) ||
			(j % 5 < 4 && j + 1 == blank) ||
			(j > 4 && j - 5 == blank) ||
			(j < 20 && j + 5 == blank)))
		{
			cout << "move" << blank << "<->" << j << endl;
			Gameboard2[j]->locate(scene2, 256 * (blank % 5), 576 - 144 * (blank / 5));
			Gameboard2[blank]->locate(scene2, 256 * (j % 5), 576 - 144 * (j / 5));

			auto s2 = Gameboard2[j];
			Gameboard2[j] = Gameboard2[blank];
			Gameboard2[blank] = s2;
			blank = j;

		}

		count++;
		if (count < 100) {
			t->set(0.1f);
			t->start();
		}
		return true;
	});

	auto timer3 = Timer::create(0.1f);
	timer3->setOnTimerCallback([&](TimerPtr t)->bool {
		cout << "timeout" << count << endl;

		int j = 0;
		switch (rand() % 4) {
		case 0: j = blank - 1; break;
		case 1: j = blank + 1; break;
		case 2: j = blank - 5; break;
		case 3: j = blank + 5; break;
		}
		if (j > 0 && j < 25 && ((j % 5 > 0 && j - 1 == blank) ||
			(j % 5 < 4 && j + 1 == blank) ||
			(j > 4 && j - 5 == blank) ||
			(j < 20 && j + 5 == blank)))
		{
			cout << "move" << blank << "<->" << j << endl;
			Gameboard3[j]->locate(scene3, 256 * (blank % 5), 576 - 144 * (blank / 5));
			Gameboard3[blank]->locate(scene3, 256 * (j % 5), 576 - 144 * (j / 5));

			auto s3 = Gameboard3[j];
			Gameboard3[j] = Gameboard3[blank];
			Gameboard3[blank] = s3;
			blank = j;

		}

		count++;
		if (count < 100) {
			t->set(0.1f);
			t->start();
		}
		return true;
	});

	 // 스타트 버튼을 눌렀을 때 타이머를 스타트하고 스타트 버튼과 화살표 버튼 하이드, 화살표 버튼 누르면 다음 신으로 이동 

	auto arrow1 = Object::create("images/화살표.jpg", scene1, 900, 320);
	arrow1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		scene2->enter();
		return true;
		});

	auto arrow2 = Object::create("images/화살표.jpg", scene2, 900, 320);
	arrow2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		scene3->enter();
		return true;
		});

	auto arrow3 = Object::create("images/화살표.jpg", scene3, 900, 320);
	arrow3->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		scene1->enter();
		return true;
		});

	auto startButton1 = Object::create("images/start.png", scene1, 600, 220);
	startButton1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		timer1->start();
		startButton1->hide();
		arrow1->hide();

		return true;
		});

	auto startButton2 = Object::create("images/start.png", scene2, 600, 220);
	startButton2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		timer2->start();
		startButton2->hide();
		arrow2->hide();
		return true;
		});

	auto startButton3 = Object::create("images/start.png", scene3, 600, 220);
	startButton3->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		timer3->start();
		startButton3->hide();
		arrow3->hide();
		return true;
		});

	start_time = time(NULL);
	startGame(scene1);

	return 0;
}