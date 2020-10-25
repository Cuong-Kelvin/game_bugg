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

	Texture t1;
	Texture t2;
	t1.loadFromFile("0.png");
	t2.loadFromFile("1.png");

	Sprite dinoArr[2];
	dinoArr[0] = Sprite(t1);
	dinoArr[1] = Sprite(t2);

	static const int DINO_Y_BOTTOM = HEIGHT - t1.getSize().y;
	Position dinoPos;
	dinoPos.x = 50;
	dinoPos.y = DINO_Y_BOTTOM;

	int index = 0;	
	float frame = 0.f;
	float frameSpeed = 0.4f;
	const int changeCount = 5;	

	const int gravity = 5;	
	bool isJumping = false;
	bool isBottom = true;	

	Texture t3;
	t3.loadFromFile("tree.png");
	Sprite tree(t3);

	static const int TREE_Y_BOTTOM = HEIGHT - t3.getSize().y;	
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
			dinoPos.y -= gravity; 
		}
		else
		{
			dinoPos.y += gravity;
		}
		
		if (dinoPos.y >= DINO_Y_BOTTOM)
		{
			dinoPos.y = DINO_Y_BOTTOM;
			isBottom = true;
		}
		if (dinoPos.y <= DINO_Y_BOTTOM - 100)
		{
			isJumping = false;
		}

		
		frame += frameSpeed;
		if (frame > changeCount)
		{
			frame -= changeCount;
			++index;
			if (index >= 2) { index = 0; }
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

		
		dinoArr[index].setPosition(dinoPos.x, dinoPos.y);

		
		window.clear();
		window.draw(dinoArr[index]);
		//window.draw(bk);
		window.draw(tree);
		window.display();
	}
}