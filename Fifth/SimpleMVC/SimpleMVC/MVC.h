#include <iostream> 
#include <vector>
#include <string>

//get Surfacespace related stuff 
using std::cin;
using std::cout;
using std::endl;
using std::flush;
using std::string;
using std::vector;

struct Observer //观察者
{
	//update 
	virtual void update(void*) = 0;
};

struct Observable
{
	//observers 
	vector<Observer*>observers;

	//addObserver 
	void addObserver(Observer*a){ observers.push_back(a); }

	//notifyObservers 
	void notifyObservers()
	{
		for (vector<Observer*>::const_iterator observer_iterator = observers.begin(); observer_iterator != observers.end(); observer_iterator++)
			(*observer_iterator)->update(this);
	}
};
struct Model:Observable
{
	//data members Radius_caption, Volume_caption, Surface_caption 
	string Radius_caption;
	string Volume_caption;
	string Surface_caption;

	//data members Radius, Volume, Surface 
	float Radius;
	float Volume;
	float Surface;

	//constructor 
	Model():
		Radius_caption("Radius: "),
		Volume_caption("Volume: "),
		Surface_caption("Surface: "),
		Radius(0),
		Volume(0),
		Surface(0)
	{ }

	//getSurface_Caption, getRadius_Caption, getVolume_Caption 
	string getSurface_Caption(){ return Surface_caption; }
	string getRadius_Caption(){ return Radius_caption; }
	string getVolume_Caption(){ return Volume_caption; }

	//getSurface, getRadius, getVolume 
	float getSurface(){ return Surface; }
	float getRadius(){ return Radius; }
	float getVolume(){ return Volume; }

	//setSurface, setRadius, setVolume 
	void setSurface(float a){ Surface = a; }
	void setRadius(float a){ Radius = a; } //notifyObservers();
	void setVolume(float a){ Volume = a; } //notifyObservers();
};
struct RadiusView :Observer
{
	void update(void*a) //这相当于对界面显示的操作 需要将界面类保存进来 
	{
		cout << static_cast<Model*>(a)->getRadius_Caption();
		cout << static_cast<Model*>(a)->getRadius();
		cout << endl;
	}
};

struct VolumeView :Observer
{
	void update(void*a)
	{
		cout << static_cast<Model*>(a)->getVolume_Caption();
		cout << static_cast<Model*>(a)->getVolume();
		cout << endl;
	}
};

struct SurfaceView :Observer
{
	void update(void*a)
	{
		cout << static_cast<Model*>(a)->getSurface_Caption();
		cout << static_cast<Model*>(a)->getSurface();
		cout << endl;
	}
};

struct Views :Observer
{
	//data members Radiusview, Volumeview, Surfaceview 
	RadiusView Radiusview;
	VolumeView Volumeview;
	SurfaceView Surfaceview;
	
	//setModel 
	void setModel(Observable&a)
	{
		a.addObserver(&Radiusview);
		a.addObserver(&Volumeview);
		a.addObserver(&Surfaceview);
		a.addObserver(this);
	}

	void update(void*a)
	{
		cout <<"————————————\n";
		cout << "Type r to edit Radius,\n";
		cout << "Type v to edit Volume,\n";
		cout << "Type s to edit Surface.\n";
		cout << "Type q to quit.\n";
	}
};

struct Controller
{
	Model* model;
	float radius, volume, surface;
	void setModel(Model&a){ model = &a; }

	void MessageLoop()
	{
		char c = ' ';
		float s;		
		cin >> c;
		while (c != 'q')
		{
			cin >> s;
			switch (c)
			{
				case 's':
					surface = s;
					radius = pow(surface / 4 / 3.14, 1.0 / 2);
					volume = 4.0 / 3.0 * 3.14 * (radius*radius*radius);
					model->setSurface(surface); 
					model->setRadius(radius);
					model->setVolume(volume);
					model->notifyObservers();
					break;
				case 'r':
					radius = s;
					volume = 4.0 / 3.0 * 3.14 * (radius*radius*radius);
					surface = 4 * 3.14 * radius*radius;
					model->setSurface(surface);
					model->setRadius(radius);
					model->setVolume(volume);
					model->notifyObservers();
					break;
				case 'v':
					volume = s;
					radius = pow(3.0 * volume / 4 / 3.14, 1.0 / 3);
					surface = 4 * 3.14 * radius*radius; 
					model->setSurface(surface);
					model->setRadius(radius);
					model->setVolume(volume);
					model->notifyObservers();
					break;
			}
			cin >> c;
		}
	}
};

struct Application
{
	Model model;
	Views views;
	Controller controller;

	//constructor 
	Application()
	{
		views.setModel(model); //view设置model是为了把自己注册进去这个model
		controller.setModel(model); //控制器设置model是为了 调用设置model的函数 
		model.notifyObservers(); //model 设置完后 通知 所有的观察者 做第一次更新
	}

	//run 
	void run(){ controller.MessageLoop(); }
};