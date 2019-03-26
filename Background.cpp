#include"Background.h"

Mirror::Mirror() : Task()
	 ,m_Update(this, &Mirror::Update)
{
	//éÛêMë§ê›íË
	m_Receive.Register<Laser>(this, &Mirror::HitCheck);

	mirror1 = Rect(0, 90, 1024, 20);
	mirror2 = Rect(0, 90, 20, 230);
	mirror3 = Rect(1004, 90, 20, 230);
}

void Mirror::Update() {
	
}


void Mirror::HitCheck(Laser &particle) {
	if (mirror1.intersects(particle.getCircle())) {
		particle.Convert_y();
	}
	else if(mirror2.intersects(particle.getCircle()) || mirror3.intersects(particle.getCircle())) {
		particle.Convert_x();
	}
}

//------------------------------------------

Back::Back() {

}

void Back::Draw() {
	TextureAsset(L"Back").draw();
	
	//Window::ClientRect().draw(Color(20, 20, 50));
	Rect(0, 320, 1024, 320).draw(Color(30, 30, 200, 80));
	Rect(0, 390, 1024, 250).draw(Color(50, 50, 200, 80));
	Rect(0, 480, 1024, 160).draw(Color(70, 70, 250, 80));
	Rect(0, 630, 1024, 10).draw(Color(170, 170, 170, 180));

	Line(0, 530, 1024, 530).draw(5, Color(200, 200, 0));

	
}

void Mirror_Draw() {
	//mirror_draw
	Rect(0, 90, 1024, 20).draw(Color(170, 170, 170));
	Rect(0, 90, 20, 230).draw(Color(170, 170, 170));
	Rect(1004, 90, 20, 230).draw(Color(170, 170, 170));
}