#include<SFML/Graphics.hpp>
using namespace sf;


#define WIDTH  900
#define HEIGHT 800

struct Position {
	int x, y;
};

int main() {
	Texture bg;
	bg.loadFromFile("anhna.png");
	Sprite bk;
	bk.setTexture(bg);
	RenderWindow window(VideoMode(bg.getSize().x, bg.getSize().y), "Cuong_7_nui");
	window.setFramerateLimit(60);

	Texture t1, t2, t3, t4, t5, t6;
	t1.loadFromFile("0.png");
	t2.loadFromFile("1.png");
	t3.loadFromFile("2.png");
	t4.loadFromFile("3.png");
	t5.loadFromFile("4.png");
	t6.loadFromFile("5.png");
	Sprite GunArr[6];
	GunArr[0] = Sprite(t1);
	GunArr[1] = Sprite(t2);
	GunArr[2] = Sprite(t3);
	GunArr[3] = Sprite(t4);
	GunArr[4] = Sprite(t5);
	GunArr[5] = Sprite(t6);
	static const int Gun_Y_BOTTOM = HEIGHT - t1.getSize().y;
	Position GunPos;
	GunPos.x = 50;
	GunPos.y = Gun_Y_BOTTOM;

	int index = 0;	
	float frame = 0.f;
	float frameSpeed = 0.4f;
	const int changeCount = 5;	

	const int gravity = 5;	
	bool isJumping = false;
	bool isBottom = true;	

	Texture tt3;
	tt3.loadFromFile("tree.png");
	Sprite tree(tt3);

	static const int TREE_Y_BOTTOM = HEIGHT - tt3.getSize().y;	
	Position treePos;
	treePos.x = WIDTH - 20;
	treePos.y = TREE_Y_BOTTOM;

	const int treeSpeed = 4;	


	while (window.isOpen() )
	{
		Event e;
		while (window.pollEvent(e)) {
			if (e.type == Event::Closed) {
				window.close();
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Space))
		{
			if (isBottom && !isJumping)
			{
				isJumping = true;
				isBottom = false;
			}
		}


		if (isJumping)
		{
			GunPos.y -= gravity; 
		}
		else
		{
			GunPos.y += gravity;
		}
		
		if (GunPos.y >= Gun_Y_BOTTOM)
		{
			GunPos.y = Gun_Y_BOTTOM;
			isBottom = true;
		}
		if (GunPos.y <= Gun_Y_BOTTOM - 100)
		{
			isJumping = false;
		}

		
		frame += frameSpeed;
		if (frame > changeCount)
		{
			frame -= changeCount;
			++index;
			if (index >= 6) { index = 0; }
		}

	
		if (treePos.x <= 0)
		{
			treePos.x = WIDTH;
		}
		else
		{
			treePos.x -= treeSpeed;
		}

		
		tree.setPosition(treePos.x, treePos.y);

		
		GunArr[index].setPosition(GunPos.x, GunPos.y);

		
		window.clear();
		window.draw(bk);
		window.draw(GunArr[index]);
		
		window.draw(tree);
		window.display();
	}
}