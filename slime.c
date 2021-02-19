#include <GL/glut.h>

void idle(void) {
  glutPostRedisplay();
}

void display(void) {
  int i, j;
  static int r = 0;
  GLdouble vertex[8][3] = {
    {0.0, 0.0, 0.0}, {1.0, 0.0, 0.0},
    {1.0, 1.0, 0.0}, {0.0, 1.0, 0.0},
    {0.0, 0.0, 1.0}, {1.0, 0.0, 1.0},
    {1.0, 1.0, 1.0}, {0.0, 1.0, 1.0}
  };
  GLdouble righteye[8][3] = {
    {0.02+0.66, 0.50+0.33, 1.00+0.02-0.25}, {0.02+0.66, 0.50, 1.00+0.02-0.25},
    {0.02+0.33+0.66, 0.50, 1.00+0.02-0.25}, {0.02+0.33+0.66, 0.50+0.33, 1.00+0.02-0.25},
    {0.02+0.66, 0.50+0.33, 1.00+0.02}, {0.02+0.66, 0.50, 1.00+0.02},
    {0.02+0.33+0.66, 0.50, 1.00+0.02}, {0.02+0.33+0.66, 0.50+0.33, 1.00+0.02}
  };
  GLdouble lefteye[8][3] = {
    {-0.02, 0.50+0.33, 1.00+0.02-0.25}, {-0.02, 0.50, 1.00+0.02-0.25},
    {-0.02+0.33, 0.50, 1.00+0.02-0.25}, {-0.02+0.33, 0.50+0.33, 1.00+0.02-0.25},
    {-0.02, 0.50+0.33, 1.00+0.02}, {-0.02, 0.50, 1.00+0.02},
    {-0.02+0.33, 0.50, 1.00+0.02}, {-0.02+0.33, 0.50+0.33, 1.00+0.02}
  };
  GLdouble mouth[8][3] = {
    {0.50, 0.33, 1.00+0.02-0.12}, {0.50, 0.16, 1.00+0.02-0.12},
    {0.50+0.16, 0.16, 1.00+0.02-0.12}, {0.50+0.16, 0.33, 1.00+0.02-0.12},
    {0.50, 0.33, 1.00+0.02}, {0.50, 0.16, 1.00+0.02},
    {0.50+0.16, 0.16, 1.00+0.02}, {0.50+0.16, 0.33, 1.00+0.02}
  };
  GLdouble wrap[8][3] = {
    {-0.16, -0.16, -0.16}, {1.16, -0.16, -0.16},
    {1.16, 1.16, -0.16}, {-0.16, 1.16, -0.16},
    {-0.16, -0.16, 1.16}, {1.16, -0.16, 1.16},
    {1.16, 1.16, 1.16}, {-0.16, 1.16, 1.16}
  };
  int face[6][4] = {
    {0, 3, 2, 1}, {1, 2, 6, 5}, {4, 5, 6, 7},
    {0, 4, 7, 3}, {0, 1, 5, 4}, {2, 3, 7, 6}
  };
  int edge[12][2] = {
    {0, 1}, {1, 2}, {2, 3}, {3, 0},
    {4, 5}, {5, 6}, {6, 7}, {7, 4},
    {0, 4}, {1, 5}, {2, 6}, {3, 7},
  };

  glClear(GL_COLOR_BUFFER_BIT);

  glLoadIdentity();
  gluLookAt(3.0, 4.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
  glRotated((GLdouble) r, 0.0, 1.0, 0.0);

  glColor3d(0.38, 0.62, 0.31);  // face color
  glBegin(GL_QUADS);
  for (i = 0; i < 6; i++) {
    for (j = 0; j < 4; j++) {
      glVertex3dv(vertex[face[i][j]]);
    }
  }
  glEnd();

  glColor3d(0.33, 0.52, 0.26);  // edge color
  glBegin(GL_LINES);
  for (i = 0; i < 12; i++) {
    glVertex3dv(vertex[edge[i][0]]);
    glVertex3dv(vertex[edge[i][1]]);
  }
  glEnd();

  glColor3d(0.03, 0.08, 0.03);  // righteye color
  glBegin(GL_QUADS);
  for (i = 0; i < 6; i++) {
    for (j = 0; j < 4; j++) {
      glVertex3dv(righteye[face[i][j]]);
    }
  }
  glEnd();

  glColor3d(0.03, 0.08, 0.03);  // lefteye color
  glBegin(GL_QUADS);
  for (i = 0; i < 6; i++) {
    for (j = 0; j < 4; j++) {
      glVertex3dv(lefteye[face[i][j]]);
    }
  }
  glEnd();

  glColor3d(0.03, 0.08, 0.03);  // mouth color
  glBegin(GL_QUADS);
  for (i = 0; i < 6; i++) {
    for (j = 0; j < 4; j++) {
      glVertex3dv(mouth[face[i][j]]);
    }
  }
  glEnd();

  glColor4d(0.43, 0.72, 0.36, 0.3);  // wrap color
  glBegin(GL_QUADS);
  for (i = 0; i < 6; i++) {
    for (j = 0; j < 4; j++) {
      glVertex3dv(wrap[face[i][j]]);
    }
  }
  glEnd();

  glFlush();
  glutSwapBuffers();

  if (++r >= 360) {
    r = 0;
  }
}

void keyboard(unsigned char key, int x, int y) {
  if (key == '\033') {  // ESC key
    exit(0);
  }
}

void resize(int w, int h) {
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(30.0, 1.0, 1.0, 10.0);
  glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char *argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
  glutCreateWindow(argv[0]);
  glClearColor(0.65, 0.65, 0.65, 1.0);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_BLEND);
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  glutIdleFunc(idle);
  glutReshapeFunc(resize);
  glutMainLoop();
  return 0;
}
