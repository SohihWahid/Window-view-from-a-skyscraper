#include <GL/glut.h>

// Time variable (0.0 = evening, 1.0 = morning)
float t = 0.0f;
float transitionSpeed = 0.001f; // Adjust for faster/slower

// Sky color stages
struct Color { float r, g, b; };

// Evening → Dusk → Night → Dawn → Morning
Color skyStages[] = {
    {0.510f, 0.647f, 0.898f},  // 0.0 - Your current evening blue
    {0.333f, 0.361f, 0.847f},   // 0.25 - Deep deep blue dusk
    {0.05f,  0.05f,  0.20f},   // 0.5  - Dark night
    {0.95f,  0.60f,  0.35f},   // 0.75 - Golden dawn
    {0.53f,  0.81f,  0.98f},   // 1.0  - Bright morning sky
};
int numStages = 5;

// Lerp helper
Color lerpColor(Color a, Color b, float t) {
    return {
        a.r + (b.r - a.r) * t,
        a.g + (b.g - a.g) * t,
        a.b + (b.b - a.b) * t
    };
}

// Get current sky color based on global t
Color getCurrentSkyColor() {
    float scaled = t * (numStages - 1);      // Map t to stage range
    int idx = (int)scaled;                    // Current stage index
    if (idx >= numStages - 1) return skyStages[numStages - 1];
    float localT = scaled - idx;             // 0.0 to 1.0 within this stage
    return lerpColor(skyStages[idx], skyStages[idx + 1], localT);
}


void display() {
    Color sky = getCurrentSkyColor();
    glClearColor(sky.r, sky.g, sky.b, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 1.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(2.0f);
    //...............................World..........................................
    /*glColor3f(0.333f, 0.361f, 0.847f);
    glBegin(GL_QUADS);
        glVertex2f(-3.9f, 0.6f);
        glVertex2f(3.53f, 0.6f);
        glVertex2f(3.53f, -3.0f);
        glVertex2f(-3.9f, -3.0f);
    glEnd();
    glColor3f(0.431f, 0.533f, 0.898f);
    glBegin(GL_QUADS);
        glVertex2f(-3.9f, 0.45f);
        glVertex2f(3.53f, 0.45f);
        glVertex2f(3.53f, -3.0f);
        glVertex2f(-3.9f, -3.0f);
    glEnd();*/
    glColor3f(sky.r, sky.g, sky.b);
    glBegin(GL_QUADS);
        glVertex2f(-3.9f, 3.3f);
        glVertex2f(3.53f, 3.3f);
        glVertex2f(3.53f, -3.0f);
        glVertex2f(-3.9f, -3.0f);
    glEnd();
    //..............................building........................................
    //,,,,,,,,,back building,,,,,,,,,
    glColor3f(0.294f, 0.400f, 0.741f);
    glBegin(GL_QUADS);
        glVertex2f(-0.8f, 0.4f);
        glVertex2f(-0.75f, 0.4f);
        glVertex2f(-0.75f, -3.0f);
        glVertex2f(-0.8f, -3.0f);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2f(-0.9f, 0.35f);
        glVertex2f(-0.84f, 0.35f);
        glVertex2f(-0.84f, -3.0f);
        glVertex2f(-0.9f, -3.0f);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2f(-0.84f, 0.22f);
        glVertex2f(-0.5f, 0.22f);
        glVertex2f(-0.5f, -3.0f);
        glVertex2f(-0.84f, -3.0f);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2f(-0.36f, 0.3f);
        glVertex2f(-0.2f, 0.29f);
        glVertex2f(-0.2f, -3.0f);
        glVertex2f(-0.36f, -3.0f);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2f(-0.2f, 0.2f);
        glVertex2f(-0.1f, 0.19f);
        glVertex2f(-0.1f, -3.0f);
        glVertex2f(-0.2f, -3.0f);
    glEnd();
    glColor3f(0.251f, 0.282f, 0.710f);
    glBegin(GL_QUADS);
        glVertex2f(0.0f, 0.5f);
        glVertex2f(0.05f, 0.501f);
        glVertex2f(0.05f, -3.0f);
        glVertex2f(0.0f, -3.0f);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2f(0.06f, 0.498f);
        glVertex2f(0.11f, 0.499f);
        glVertex2f(0.11f, -3.0f);
        glVertex2f(0.06f, -3.0f);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2f(0.0f, 0.42f);
        glVertex2f(0.22f, 0.41f);
        glVertex2f(0.22f, -3.0f);
        glVertex2f(0.0f, -3.0f);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2f(0.9f, 0.45f);
        glVertex2f(0.88f, 0.455f);
        glVertex2f(0.88f, -3.0f);
        glVertex2f(0.9f, -3.0f);
    glEnd();
    glColor3f(0.294f, 0.400f, 0.741f);
    glBegin(GL_QUADS);
        glVertex2f(0.88f, 0.455f);
        glVertex2f(0.78f, 0.442f);
        glVertex2f(0.78f, -3.0f);
        glVertex2f(0.88f, -3.0f);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2f(0.6f, 0.305f);
        glVertex2f(0.64f, 0.3f);
        glVertex2f(0.64f, -3.0f);
        glVertex2f(0.6f, -3.0f);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2f(0.64f, 0.315f);
        glVertex2f(0.67f, 0.31f);
        glVertex2f(0.67f, -3.0f);
        glVertex2f(0.64f, -3.0f);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2f(0.67f, 0.22f);
        glVertex2f(0.7f, 0.2f);
        glVertex2f(0.7f, -3.0f);
        glVertex2f(0.67f, -3.0f);
    glEnd();
    //,,,,,,,,,left window tall building,,,,,,,,,
    glColor3f(0.345f, 0.184f, 0.584f);
    glBegin(GL_QUADS);
        glVertex2f(-0.55f, 0.56f);
        glVertex2f(-0.36f, 0.545f);
        glVertex2f(-0.36f, -3.0f);
        glVertex2f(-0.55f, -3.0f);
    glEnd();
    glColor3f(0.188f, 0.082f, 0.290f);
    glBegin(GL_QUADS);
        glVertex2f(-0.55f, 0.56f);
        glVertex2f(-0.7f, 0.52f);
        glVertex2f(-0.7f, -3.0f);
        glVertex2f(-0.55f, -3.0f);
    glEnd();
    glColor3f(0.157f, 0.047f, 0.310f);
    glBegin(GL_QUADS);
        glVertex2f(-0.525f, 0.51f);
        glVertex2f(-0.38f, 0.495f);
        glVertex2f(-0.38f, -3.0f);
        glVertex2f(-0.525f, -3.0f);
    glEnd();
    //,,,,,,,,,middle window middle tall building,,,,,,,
    glColor3f(0.345f, 0.184f, 0.584f);
    glBegin(GL_QUADS);
        glVertex2f(-0.05f, 0.405f);
        glVertex2f(0.148f, 0.4f);
        glVertex2f(0.148f, -3.0f);
        glVertex2f(-0.05f, -3.0f);
    glEnd();
    glColor3f(0.188f, 0.082f, 0.290f);
    glBegin(GL_QUADS);
        glVertex2f(-0.05f, 0.405f);
        glVertex2f(-0.1f, 0.355f);
        glVertex2f(-0.1f, -3.0f);
        glVertex2f(-0.05f, -3.0f);
    glEnd();
    glColor3f(0.157f, 0.047f, 0.310f);
    glBegin(GL_QUADS);
        glVertex2f(-0.03f, 0.355f);
        glVertex2f(0.13f, 0.35f);
        glVertex2f(0.13f, -3.0f);
        glVertex2f(-0.03f, -3.0f);
    glEnd();
    //,,,,,,,,,right window tall right building,,,,,
    glColor3f(0.302f, 0.345f, 0.698f);
    glBegin(GL_QUADS);
        glVertex2f(0.73f, 0.302f);
        glVertex2f(0.9f, 0.3f);
        glVertex2f(0.9f, -3.0f);
        glVertex2f(0.73f, -3.0f);
    glEnd();
    glColor3f(0.169f, 0.161f, 0.373f);
    glBegin(GL_QUADS);
        glVertex2f(0.73f, 0.302f);
        glVertex2f(0.68f, 0.28f);
        glVertex2f(0.68f, -3.0f);
        glVertex2f(0.73f, -3.0f);
    glEnd();
    glColor3f(0.157f, 0.047f, 0.310f);
    glBegin(GL_QUADS);
        glVertex2f(0.745f, 0.252f);
        glVertex2f(0.887f, 0.25f);
        glVertex2f(0.887f, -3.0f);
        glVertex2f(0.745f, -3.0f);
    glEnd();
    //,,,,,,,,,middle window tall right building,,,,,,
    glColor3f(0.345f, 0.184f, 0.584f);
    glBegin(GL_QUADS);
        glVertex2f(0.17f, 0.355f);
        glVertex2f(0.60f, 0.35f);
        glVertex2f(0.60f, -3.0f);
        glVertex2f(0.17f, -3.0f);
    glEnd();
    glColor3f(0.188f, 0.082f, 0.290f);
    glBegin(GL_QUADS);
        glVertex2f(0.17f, 0.355f);
        glVertex2f(0.148f, 0.33f);
        glVertex2f(0.148f, -3.0f);
        glVertex2f(0.17f, -3.0f);
    glEnd();
    glColor3f(0.106f, 0.043f, 0.361f);
    glBegin(GL_QUADS);
        glVertex2f(0.19f, 0.325f);
        glVertex2f(0.585f, 0.32f);
        glVertex2f(0.585f, -3.0f);
        glVertex2f(0.19f, -3.0f);
    glEnd();
    //side building
    glColor3f(0.345f, 0.184f, 0.584f);
    glBegin(GL_QUADS);
        glVertex2f(0.6f, 0.152f);
        glVertex2f(0.7f, 0.15f);
        glVertex2f(0.7f, -3.0f);
        glVertex2f(0.6f, -3.0f);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2f(0.6f, 0.172f);
        glVertex2f(0.65f, 0.17f);
        glVertex2f(0.65f, -3.0f);
        glVertex2f(0.6f, -3.0f);
    glEnd();
    glColor3f(0.106f, 0.043f, 0.361f);
    glBegin(GL_QUADS);
        glVertex2f(0.6f, 0.132f);
        glVertex2f(0.69f, 0.13f);
        glVertex2f(0.69f, -3.0f);
        glVertex2f(0.6f, -3.0f);
    glEnd();

    //,,,,,,,,,left 2nd building,,,,,,,,,
    glColor3f(0.180f, 0.125f, 0.443f);
    glBegin(GL_QUADS);
        glVertex2f(-0.715f, 0.26f);
        glVertex2f(-0.43, 0.26f);
        glVertex2f(-0.5f, 0.23f);
        glVertex2f(-0.77f, 0.23f);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2f(-0.77f, 0.23f);
        glVertex2f(-0.71f, 0.26f);
        glVertex2f(-0.71f, 0.27f);
        glVertex2f(-0.77f, 0.24f);
    glEnd();
    glColor3f(0.322f, 0.263f, 0.667f);
    glBegin(GL_QUADS);
        glVertex2f(-0.71f, 0.26f);
        glVertex2f(-0.43f, 0.26f);
        glVertex2f(-0.43f, 0.27f);
        glVertex2f(-0.71f, 0.27f);
    glEnd();
    glColor3f(0.318f, 0.259f, 0.671f);
    glBegin(GL_QUADS);
        glVertex2f(-0.71f, 0.25f);
        glVertex2f(-0.45f, 0.25f);
        glVertex2f(-0.45f, -3.0f);
        glVertex2f(-0.71f, -3.0f);
    glEnd();
    glColor3f(0.235f, 0.145f, 0.529f);
    glBegin(GL_QUADS);
        glVertex2f(-0.71f, 0.25f);
        glVertex2f(-0.75f, 0.23f);
        glVertex2f(-0.75f, -3.0f);
        glVertex2f(-0.71f, -3.0f);
    glEnd();
    //,,,,,,,,,middle window right building,,,,,,,,,,,,,,
    glColor3f(0.357f, 0.388f, 0.718f);
    glBegin(GL_QUADS);
        glVertex2f(0.507f, 0.048f);
        glVertex2f(0.148f, 0.048f);
        glVertex2f(0.148f, 0.068f);
        glVertex2f(0.507f, 0.068f);
    glEnd();
    glColor3f(0.263f, 0.184f, 0.514f);
    glBegin(GL_QUADS);
        glVertex2f(0.148f, 0.048f);
        glVertex2f(0.1f, 0.01f);
        glVertex2f(0.1f, 0.04f);
        glVertex2f(0.148f, 0.068f);
    glEnd();
    glColor3f(0.176f, 0.137f, 0.376f);
    glBegin(GL_QUADS);
        glVertex2f(0.507f, 0.048f);
        glVertex2f(0.148f, 0.048f);
        glVertex2f(0.050f, -0.010f);
        glVertex2f(0.495f, 0.018f);
    glEnd();
    glColor3f(0.357f, 0.388f, 0.718f);
    glBegin(GL_QUADS);
        glVertex2f(0.15f, 0.04f);
        glVertex2f(0.5f, 0.04f);
        glVertex2f(0.5f, -3.0f);
        glVertex2f(0.15f, -3.0f);
    glEnd();
    glColor3f(0.263f, 0.184f, 0.514f);
    glBegin(GL_QUADS);
        glVertex2f(0.15f, 0.04f);
        glVertex2f(0.1f, 0.01f);
        glVertex2f(0.1f, -3.0f);
        glVertex2f(0.15f, -3.0f);
    glEnd();


    //window
    glColor3f(1.000f, 0.980f, 0.886f);
    glBegin(GL_QUADS);
        glVertex2f(0.19f, -0.01f);
        glVertex2f(0.23f, -0.01f);
        glVertex2f(0.23f, -0.13f);
        glVertex2f(0.19f, -0.13f);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2f(0.27f, -0.01f);
        glVertex2f(0.31f, -0.01f);
        glVertex2f(0.31f, -0.13f);
        glVertex2f(0.27f, -0.13f);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2f(0.43f, -0.01f);
        glVertex2f(0.47f, -0.01f);
        glVertex2f(0.47f, -0.13f);
        glVertex2f(0.43f, -0.13f);
    glEnd();
    glColor3f(0.239f, 0.196f, 0.522f);
    glBegin(GL_QUADS);
        glVertex2f(0.35f, -0.01f);
        glVertex2f(0.39f, -0.01f);
        glVertex2f(0.39f, -0.13f);
        glVertex2f(0.35f, -0.13f);
    glEnd();
    //window border
    glColor3f(0.184f, 0.133f, 0.329f);
    glBegin(GL_QUADS);
        glVertex2f(0.39f, -0.01f);
        glVertex2f(0.385f, -0.015f);
        glVertex2f(0.385f, -0.13f);
        glVertex2f(0.39f, -0.13f);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2f(0.39f, -0.01f);
        glVertex2f(0.35f, -0.01f);
        glVertex2f(0.35f, -0.015f);
        glVertex2f(0.39f, -0.015f);
    glEnd();
    glColor3f(0.239f, 0.196f, 0.522f);
    glBegin(GL_QUADS);
        glVertex2f(0.47f, -0.01f);
        glVertex2f(0.465f, -0.015f);
        glVertex2f(0.465f, -0.13f);
        glVertex2f(0.47f, -0.13f);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2f(0.47f, -0.01f);
        glVertex2f(0.43f, -0.01f);
        glVertex2f(0.43f, -0.015f);
        glVertex2f(0.47f, -0.015f);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2f(0.23f, -0.01f);
        glVertex2f(0.225f, -0.015f);
        glVertex2f(0.225f, -0.13f);
        glVertex2f(0.23f, -0.13f);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2f(0.23f, -0.01f);
        glVertex2f(0.19f, -0.01f);
        glVertex2f(0.19f, -0.015f);
        glVertex2f(0.23f, -0.015f);
    glEnd();
    //,,,,,,,,,building that going through left and middle window,,,,,,,
    glColor3f(0.133f, 0.078f, 0.318f);
    glBegin(GL_QUADS);
        glVertex2f(-0.315f, 0.155f);
        glVertex2f(-0.14f, 0.155f);
        glVertex2f(-0.17f, 0.12f);
        glVertex2f(-0.415f, 0.11f);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2f(-0.415f, 0.11f);
        glVertex2f(-0.315f, 0.155f);
        glVertex2f(-0.315f, 0.17f);
        glVertex2f(-0.415f, 0.127f);
    glEnd();
    glColor3f(0.239f, 0.196f, 0.522f);
    glBegin(GL_QUADS);
        glVertex2f(-0.315f, 0.155f);
        glVertex2f(-0.14f, 0.155f);
        glVertex2f(-0.14f, 0.17f);
        glVertex2f(-0.315f, 0.17f);
    glEnd();

    glColor3f(0.251f, 0.345f, 0.714f);
    glBegin(GL_QUADS);
        glVertex2f(-0.3f, 0.15f);
        glVertex2f(-0.15f, 0.15f);
        glVertex2f(-0.15f, -3.0f);
        glVertex2f(-0.3f, -3.0f);
    glEnd();
    glColor3f(0.200f, 0.176f, 0.514f);
    glBegin(GL_QUADS);
        glVertex2f(-0.4f, 0.11f);
        glVertex2f(-0.3f, 0.15f);
        glVertex2f(-0.3f, -3.0f);
        glVertex2f(-0.4f, -3.0f);
    glEnd();
    glColor3f(0.133f, 0.078f, 0.318f);
    glBegin(GL_QUADS);
        glVertex2f(-0.25f, 0.145f);
        glVertex2f(-0.185f, 0.145f);
        glVertex2f(-0.185f, 0.15f);
        glVertex2f(-0.25f, 0.15f);
    glEnd();
    glColor3f(0.141f, 0.169f, 0.471f);
    glBegin(GL_QUADS);
        glVertex2f(-0.195f, 0.14f);
        glVertex2f(-0.185f, 0.15f);
        glVertex2f(-0.185f, -3.0f);
        glVertex2f(-0.195f, -3.0f);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2f(-0.25f, 0.13f);
        glVertex2f(-0.185f, 0.13f);
        glVertex2f(-0.185f, 0.145f);
        glVertex2f(-0.25f, 0.145f);
    glEnd();
    //,,,,,,,,,middle window middle building
    glColor3f(0.388f, 0.349f, 0.620f);
    glBegin(GL_QUADS);
        glVertex2f(-0.15f, 0.1f);
        glVertex2f(0.1f, 0.1f);
        glVertex2f(0.1f, -3.0f);
        glVertex2f(-0.15f, -3.0f);
    glEnd();
    glColor3f(0.176f, 0.137f, 0.376f);
    glBegin(GL_QUADS);
        glVertex2f(-0.15f, 0.1f);
        glVertex2f(0.1f, 0.1f);
        glVertex2f(0.11f, 0.105f);
        glVertex2f(-0.15f, 0.105f);
    glEnd();
    glColor3f(0.239f, 0.196f, 0.522f);
    glBegin(GL_QUADS);
        glVertex2f(-0.15f, 0.105f);
        glVertex2f(0.11f, 0.105f);
        glVertex2f(0.11f, 0.125f);
        glVertex2f(-0.15f, 0.125f);
    glEnd();
    //window
    glBegin(GL_QUADS);
        glVertex2f(0.02f, 0.05f);
        glVertex2f(0.07f, 0.05f);
        glVertex2f(0.07f, -0.12f);
        glVertex2f(0.02f, -0.12f);
    glEnd();
    glColor3f(1.000f, 0.980f, 0.886f);
    glBegin(GL_QUADS);
        glVertex2f(-0.01f, 0.05f);
        glVertex2f(-0.06f, 0.05f);
        glVertex2f(-0.06f, -0.12f);
        glVertex2f(-0.01f, -0.12f);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2f(-0.09f, 0.05f);
        glVertex2f(-0.14f, 0.05f);
        glVertex2f(-0.14f, -0.12f);
        glVertex2f(-0.09f, -0.12f);
    glEnd();
    //window border
    glColor3f(0.239f, 0.196f, 0.522f);
    glBegin(GL_QUADS);
        glVertex2f(-0.09f, 0.05f);
        glVertex2f(-0.095f, 0.045f);
        glVertex2f(-0.095f, -0.12f);
        glVertex2f(-0.09f, -0.12f);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2f(-0.095f, 0.045f);
        glVertex2f(-0.14f, 0.045f);
        glVertex2f(-0.14f, 0.05f);
        glVertex2f(-0.09f, 0.05f);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2f(-0.01f, 0.05f);
        glVertex2f(-0.015f, 0.045f);
        glVertex2f(-0.015f, -0.12f);
        glVertex2f(-0.01f, -0.12f);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2f(-0.015f, 0.045f);
        glVertex2f(-0.06f, 0.045f);
        glVertex2f(-0.06f, 0.05f);
        glVertex2f(-0.01f, 0.05f);
    glEnd();
    glColor3f(0.184f, 0.133f, 0.329f);
    glBegin(GL_QUADS);
        glVertex2f(0.07f, 0.05f);
        glVertex2f(0.065f, 0.045f);
        glVertex2f(0.065f, -0.12f);
        glVertex2f(0.07f, -0.12f);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2f(0.065f, 0.045f);
        glVertex2f(0.02f, 0.045f);
        glVertex2f(0.02f, 0.05f);
        glVertex2f(0.07f, 0.05f);
    glEnd();

    //,,,,,,,,,left 1st building,,,,,,,,,
    Color bgcolor = lerpColor({0.247f, 0.235f, 0.635f},
                             {0.627f, 0.698f, 0.737f},
                              t);
    glColor3f(0.416f, 0.298f, 0.635f);
    glColor3f(bgcolor.r, bgcolor.g, bgcolor.b);
    glBegin(GL_QUADS);
        glVertex2f(-0.9f, 0.05f);
        glVertex2f(-0.53f, 0.05f);
        glVertex2f(-0.53f, -3.0f);
        glVertex2f(-0.9f, -3.0f);
    glEnd();
    Color window_glass = lerpColor({0.180f, 0.094f, 0.412f},
                             {0.400f, 0.447f, 0.522f},
                              t);
    glColor3f(window_glass.r, window_glass.g, window_glass.b);
    glBegin(GL_QUADS);
        glVertex2f(-0.85f, 0.00f);
        glVertex2f(-0.75f, 0.00f);
        glVertex2f(-0.75f, -3.0f);
        glVertex2f(-0.85f, -3.0f);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2f(-0.7f, 0.00f);
        glVertex2f(-0.6f, 0.00f);
        glVertex2f(-0.6f, -3.0f);
        glVertex2f(-0.7f, -3.0f);
    glEnd();
    Color border_color = lerpColor({0.278f, 0.141f, 0.486f},
                             {0.557f, 0.400f, 0.369f},
                              t);
    glColor3f(border_color.r, border_color.g, border_color.b);
    glBegin(GL_QUADS);
        glVertex2f(-0.6f, 0.005f);
        glVertex2f(-0.61f, 0.00f);
        glVertex2f(-0.61f, -3.0f);
        glVertex2f(-0.6f, -3.0f);
    glEnd();
    glColor3f(border_color.r, border_color.g, border_color.b);
    glBegin(GL_QUADS);
        glVertex2f(-0.6f, 0.005f);
        glVertex2f(-0.61f, 0.00f);
        glVertex2f(-0.7f, 0.00f);
        glVertex2f(-0.7f, 0.005f);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2f(-0.75f, 0.005f);
        glVertex2f(-0.76f, 0.00f);
        glVertex2f(-0.76f, -3.0f);
        glVertex2f(-0.75f, -3.0f);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2f(-0.75f, 0.005f);
        glVertex2f(-0.755f, 0.00f);
        glVertex2f(-0.85f, 0.00f);
        glVertex2f(-0.85f, 0.005f);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2f(-0.575f, 0.05f);
        glVertex2f(-0.59f, 0.03f);
        glVertex2f(-0.59f, -3.0f);
        glVertex2f(-0.575f, -3.0f);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2f(-0.575f, 0.045f);
        glVertex2f(-0.59f, 0.025f);
        glVertex2f(-0.85f, 0.025f);
        glVertex2f(-0.85f, 0.045f);
    glEnd();
    glColor3f(0.129f, 0.078f, 0.365f);
    glBegin(GL_QUADS);
        glVertex2f(-0.575f, 0.05f);
        glVertex2f(-0.578f, 0.045f);
        glVertex2f(-0.85f, 0.045f);
        glVertex2f(-0.85f, 0.05f);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2f(-0.9f, 0.05f);
        glVertex2f(-0.53f, 0.05f);
        glVertex2f(-0.52f, 0.06f);
        glVertex2f(-0.95f, 0.06f);
    glEnd();
    glColor3f(0.239f, 0.196f, 0.522f);
    glBegin(GL_QUADS);
        glVertex2f(-0.95f, 0.06f);
        glVertex2f(-0.52f, 0.06f);
        glVertex2f(-0.52f, 0.075f);
        glVertex2f(-0.95f, 0.075f);
    glEnd();
    //..............................interior........................................
    //floor
    Color floor = lerpColor({0.247f, 0.235f, 0.635f},
                             {0.627f, 0.698f, 0.737f},
                              t);
    //glColor3f(0.247f, 0.235f, 0.635f);
    glColor3f(floor.r, floor.g, floor.b);
    glBegin(GL_QUADS);
        glVertex2f(-3.0f, -0.4f);
        glVertex2f(3.0f,  -0.4f);
        glVertex2f(3.0f, -3.0f);
        glVertex2f(-3.0f, -3.0f);
    glEnd();
    //Left window
    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.9f,  0.6f);
        glVertex2f( -0.35f,  0.6f);
        glVertex2f( -0.35f, -0.4f);
        glVertex2f(-0.9f, -0.4f);
    glEnd();
    //middle window
    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.25f,  0.6f);
        glVertex2f( 0.25f,  0.6f);
        glVertex2f( 0.25f, -0.4f);
        glVertex2f(-0.25f, -0.4f);
    glEnd();
    //right window
    glBegin(GL_LINE_LOOP);
        glVertex2f(0.35f,  0.6f);
        glVertex2f( 0.9f,  0.6f);
        glVertex2f( 0.9f, -0.4f);
        glVertex2f(0.35f, -0.4f);
    glEnd();
    Color window_side_pillar = lerpColor({0.639f, 0.796f, 1.000f},
                             {0.953f, 0.918f, 0.867f},
                              t);
    //left window side pillar
    glColor3f(window_side_pillar.r, window_side_pillar.g, window_side_pillar.b);
    glBegin(GL_QUADS);
        glVertex2f(-0.9f,  0.602f);
        glVertex2f( -0.95f,  0.65f);
        glVertex2f( -0.925f, -0.415f);
        glVertex2f(-0.9f, -0.403f);
    glEnd();
    Color window_shadow = lerpColor({0.227f, 0.220f, 0.647f},
                             {0.569f, 0.612f, 0.678f},
                              t);
    //left window side pillar shadow
    glColor3f(window_shadow.r, window_shadow.g, window_shadow.b);
    glBegin(GL_QUADS);
        glVertex2f(-0.9f,  0.602f);
        glVertex2f( -0.95f,  0.65f);
        glVertex2f( -0.945f, 0.3f);
        glVertex2f(-0.9f, 0.403f);
    glEnd();
    Color window_top_pillar_shadow = lerpColor({0.294f, 0.341f, 0.886f},
                             {0.667f, 0.675f, 0.725f},
                              t);
    //left window top pillar
    glColor3f(window_top_pillar_shadow.r, window_top_pillar_shadow.g, window_top_pillar_shadow.b);
    glBegin(GL_QUADS);
        glVertex2f(-0.9f,  0.602f);
        glVertex2f( -0.95f,  0.65f);
        glVertex2f( -0.353f, 0.65f);
        glVertex2f(-0.353f, 0.602f);
    glEnd();
    //middle window top pillar
    glColor3f(window_top_pillar_shadow.r, window_top_pillar_shadow.g, window_top_pillar_shadow.b);
    glBegin(GL_QUADS);
        glVertex2f(-0.252f,  0.6f);
        glVertex2f( -0.27f,  0.65f);
        glVertex2f( 0.27f, 0.65f);
        glVertex2f(0.252f, 0.6f);
    glEnd();
    //middle window left piller
    glColor3f(window_side_pillar.r, window_side_pillar.g, window_side_pillar.b);
    glBegin(GL_QUADS);
        glVertex2f(-0.25f,  0.6f);
        glVertex2f( -0.27f,  0.65f);
        glVertex2f( -0.26f, -0.415f);
        glVertex2f(-0.25f, -0.405f);
    glEnd();
    //middle window right piller
    glColor3f(window_side_pillar.r, window_side_pillar.g, window_side_pillar.b);
    glBegin(GL_QUADS);
        glVertex2f(0.25f,  0.6f);
        glVertex2f(0.27f,  0.65f);
        glVertex2f( 0.26f, -0.415f);
        glVertex2f(0.25f, -0.405f);
    glEnd();
    //middle window left shadow
    glColor3f(window_shadow.r, window_shadow.g, window_shadow.b);
    glBegin(GL_QUADS);
        glVertex2f(-0.25f,  0.6f);
        glVertex2f( -0.3f,  0.75f);
        glVertex2f( -0.295f, 0.3f);
        glVertex2f(-0.25f, 0.403f);
    glEnd();
    //middle window right shadow
    glColor3f(window_shadow.r, window_shadow.g, window_shadow.b);
    glBegin(GL_QUADS);
        glVertex2f(0.25f,  0.6f);
        glVertex2f(0.3f,  0.75f);
        glVertex2f(0.295f, 0.3f);
        glVertex2f(0.25f, 0.403f);
    glEnd();
    //right window right piller
    glColor3f(window_side_pillar.r, window_side_pillar.g, window_side_pillar.b);
    glBegin(GL_QUADS);
        glVertex2f(0.9f,  0.6f);
        glVertex2f(0.95f,  0.65f);
        glVertex2f( 0.925f, -0.415f);
        glVertex2f(0.9f, -0.4f);
    glEnd();
    //right window top piller
    glColor3f(window_top_pillar_shadow.r, window_top_pillar_shadow.g, window_top_pillar_shadow.b);
    glBegin(GL_QUADS);
        glVertex2f(0.35f,  0.6f);
        glVertex2f(0.35f,  0.65f);
        glVertex2f( 0.95f, 0.65f);
        glVertex2f(0.9f, 0.6f);
    glEnd();
    //right window right shadow
    glColor3f(window_shadow.r, window_shadow.g, window_shadow.b);
    glBegin(GL_QUADS);
        glVertex2f(0.9f,  0.6f);
        glVertex2f(0.95f,  0.65f);
        glVertex2f( 0.945f, 0.3f);
        glVertex2f(0.9f, 0.4f);
    glEnd();

    Color wall = lerpColor({0.196f, 0.086f, 0.490f},
                             {0.310f, 0.388f, 0.498f},
                              t);
    //middle window and right window attach piller
    glColor3f(wall.r, wall.g, wall.b);
    glBegin(GL_QUADS);
        glVertex2f(0.266f,  0.65f);
        glVertex2f( 0.354f,  0.65f);
        glVertex2f( 0.352f, -0.415f);
        glVertex2f(0.26f, -0.415f);
    glEnd();
    //middle window and left window attach piller
    glColor3f(wall.r, wall.g, wall.b);
    glBegin(GL_QUADS);
        glVertex2f(-0.27f,  0.65f);
        glVertex2f( -0.353f,  0.65f);
        glVertex2f( -0.352f, -0.415f);
        glVertex2f(-0.26f, -0.415f);
    glEnd();
    //left wall
    glColor3f(wall.r, wall.g, wall.b);
    glBegin(GL_QUADS);
        glVertex2f(-0.95f,  0.65f);
        glVertex2f( -3.0f,  0.65f);
        glVertex2f( -3.0f, -0.415f);
        glVertex2f(-0.925f, -0.415f);
    glEnd();
    //right wall
    glColor3f(wall.r, wall.g, wall.b);
    glBegin(GL_QUADS);
        glVertex2f(0.95f,  0.65f);
        glVertex2f(3.0f,  0.65f);
        glVertex2f(3.0f, -0.415f);
        glVertex2f(0.925f, -0.415f);
    glEnd();
    //top wall
    //glColor3f(0.133f, 0.118f, 0.486f);
    glColor3f(wall.r, wall.g, wall.b);
    glBegin(GL_QUADS);
        glVertex2f(-3.0f, 0.65f);
        glVertex2f(3.0f,  0.65f);
        glVertex2f(3.0f, 0.75f);
        glVertex2f(-3.0f, 0.75f);
    glEnd();
    //ceiling
    glColor3f(0.247f, 0.235f, 0.635f);
    glBegin(GL_QUADS);
        glVertex2f(-3.0f, 0.75f);
        glVertex2f(3.0f,  0.75f);
        glVertex2f(3.0f, 3.0f);
        glVertex2f(-3.0f, 3.0f);
    glEnd();
    Color floor_shade = lerpColor({0.463f, 0.651f, 0.902f},
                             {0.902f, 0.902f, 0.871f},
                              t);
    //left floor shade
    glColor3f(floor_shade.r, floor_shade.g, floor_shade.b);
    glBegin(GL_QUADS);
        glVertex2f(-0.9f, -0.4f);
        glVertex2f( -0.352f, -0.4f);
        glVertex2f(-2.15f, -3.0f);
        glVertex2f(-5.0f, -3.0f);
    glEnd();
    //middle floor shade
    glColor3f(floor_shade.r, floor_shade.g, floor_shade.b);
    glBegin(GL_QUADS);
        glVertex2f(-0.25f, -0.4f);
        glVertex2f( 0.25f, -0.4f);
        glVertex2f(2.0f, -3.0f);
        glVertex2f(-1.7f, -3.0f);
    glEnd();
    //right floor shade
    glColor3f(floor_shade.r, floor_shade.g, floor_shade.b);
    glBegin(GL_QUADS);
        glVertex2f(0.35f, -0.4f);
        glVertex2f( 0.9f, -0.4f);
        glVertex2f(5.0f, -3.0f);
        glVertex2f(2.5f, -3.0f);
    glEnd();

    glFlush();
    glutSwapBuffers();
}
void update(int value) {
    if (t < 1.0f) {
        t += transitionSpeed;
        if (t > 1.0f) t = 1.0f;
    }
    glutPostRedisplay();
    glutTimerFunc(16, update, 0); // ~60 FPS
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1400, 900);
    glutInitWindowPosition(300, 50);
    glutCreateWindow("Project");

    glutDisplayFunc(display);
    glutTimerFunc(16, update, 0);
    glutMainLoop();

    return 0;
}
