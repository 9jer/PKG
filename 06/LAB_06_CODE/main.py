import pygame
from pygame.locals import *
from OpenGL.GL import *
from OpenGL.GLU import *

vertices = (
    (0.2, -0.2, -0.3),
    (0.2, -0.2, 0.3),
    (0.2, 0.3, 0.3),
    (0.2, 0.3, 0.1),
    (0.2, 0.0, 0.1),
    (0.2, 0.0, -0.1),
    (0.2, 0.3, -0.1),
    (0.2, 0.3, -0.3),

    (-0.2, -0.2, -0.3),
    (-0.2, -0.2, 0.3),
    (-0.2, 0.3, 0.3),
    (-0.2, 0.3, 0.1),
    (-0.2, 0.0, 0.1),
    (-0.2, 0.0, -0.1),
    (-0.2, 0.3, -0.1),
    (-0.2, 0.3, -0.3),
)

edges = (
    (0, 1), (1, 2), (2, 3), (3, 4), (4, 5), (5, 6), (6, 7), (7, 0),
    (8, 9), (9, 10), (10, 11), (11, 12), (12, 13), (13, 14), (14, 15), (15, 8),
    (0, 8), (1, 9), (2, 10), (3, 11), (4, 12), (5, 13), (6, 14), (7, 15),
)

rotation_speed = 20.0
scale_factor = 1.0
translation_speed = 0.1

def draw_axes(length=1.0):
    glBegin(GL_LINES)
    glColor3f(1, 0, 0)  # Red color for X-axis
    glVertex3f(0, 0, 0)
    glVertex3f(length, 0, 0)

    glColor3f(0, 1, 0)  # Green color for Y-axis
    glVertex3f(0, 0, 0)
    glVertex3f(0, length, 0)

    glColor3f(0, 0, 1)  # Blue color for Z-axis
    glVertex3f(0, 0, 0)
    glVertex3f(0, 0, length)
    glEnd()

def draw_cube():
    glPushMatrix()
    glScalef(scale_factor, scale_factor, scale_factor)
    glTranslatef(0.0, 0.0, translation_speed)

    glColor3f(1, 1, 1)

    glBegin(GL_LINES)
    for edge in edges:
        for vertex in edge:
            glVertex3fv(vertices[vertex])
    glEnd()
    glPopMatrix()

def main():
    pygame.init()
    display = (800, 600)
    pygame.display.set_mode(display, DOUBLEBUF | OPENGL)
    gluPerspective(45, (display[0] / display[1]), 0.1, 50.0)
    glTranslatef(0.0, 0.0, -5)

    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()
            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_LEFT:
                    glRotatef(rotation_speed, 0, 2, 0)
                elif event.key == pygame.K_RIGHT:
                    glRotatef(-rotation_speed, 0, 2, 0)
                elif event.key == pygame.K_UP:
                    glRotatef(rotation_speed, 2, 0, 0)
                elif event.key == pygame.K_DOWN:
                    glRotatef(-rotation_speed, 2, 0, 0)
                elif event.key == pygame.K_w:
                    glScalef(1.1, 1.1, 1.1)
                elif event.key == pygame.K_s:
                    glScalef(0.9, 0.9, 0.9)
                elif event.key == pygame.K_a:
                    glTranslatef(-translation_speed, 0, 0)
                elif event.key == pygame.K_d:
                    glTranslatef(translation_speed, 0, 0)

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)

        # Draw the axes
        draw_axes()

        # Draw the cube
        draw_cube()

        pygame.display.flip()
        pygame.time.wait(10)

if __name__ == "__main__":
    main()