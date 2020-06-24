#include <iostream>
//#include <GL/glut.h>
#include <GL/freeglut.h>
#include <vector>
using namespace std;
int MouseX = 0, MouseY = 0;
vector<char> arr;
vector<char>::iterator cek;
void printOut(void);
void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}
void keyboardDown(unsigned char key, int x, int y) {
	cek = find(arr.begin(), arr.end(), key);
	if (cek == arr.end()) arr.push_back(key);
	printOut();
}

void keyboardUp(unsigned char key, int x, int y) {
	cek = find(arr.begin(), arr.end(), key);
	if (cek != arr.end()) {
		int index = distance(arr.begin(), cek);
		arr.erase(arr.begin() + index);
	} printOut();
}
void printOut() {
	system("cls");
	cout << "MouseX: " << MouseX << " | " << "MouseY: " << MouseY << endl;
	for(auto it : arr) cout << it << ' ';
}

void mouse(int x, int y) {
	MouseX = x;
	MouseY = y;
	printOut();
}

void mouseButton(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && (state == GLUT_DOWN || state == GLUT_UP)) {
		MouseX = x;
		MouseY = y;
	}
	printOut();
}
void myinit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 1.0, 0.0, 1.0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(50, 50);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Empty");
	glutDisplayFunc(display);
	glutMotionFunc(mouse);				  // when mouse move
	glutMouseFunc(mouseButton);			  // when left mouse button clicked
	glutKeyboardFunc(keyboardDown);       // when a key is down
	glutKeyboardUpFunc(keyboardUp);       // when the key goes up
	myinit();
	glutMainLoop();
	return 0;
}