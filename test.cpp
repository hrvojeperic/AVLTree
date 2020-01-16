#include <iostream>
#include <vector>
#include "avl.h"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
using namespace std;

// multiple test cases for AVL tree class correctness

TEST_CASE("(1) empty tree") {

    avltree<int, int>  avl;

    REQUIRE(avl.size() == 0);
    REQUIRE(avl.height() == -1);

}

TEST_CASE("(2) AVL tree with 4 nodes") {

    avltree<int, int>  avl;
    avl.insert(100, -100);
    avl.insert(50, -50);
    avl.insert(150, -150);
    avl.insert(125, -125);

    vector<int>  keys, values, heights;
    keys = avl.inorder_keys();
    values = avl.inorder_values();
    heights = avl.inorder_heights();

    REQUIRE(avl.size() == 4);
    REQUIRE(avl.height() == 2);

    REQUIRE(keys[0] == 50);
    REQUIRE(values[0] == -50);
    REQUIRE(heights[0] == 0);

    REQUIRE(keys[1] == 100);
    REQUIRE(values[1] == -100);
    REQUIRE(heights[1] == 2);

    REQUIRE(keys[2] == 125);
    REQUIRE(values[2] == -125);
    REQUIRE(heights[2] == 0);

    REQUIRE(keys[3] == 150);
    REQUIRE(values[3] == -150);
    REQUIRE(heights[3] == 1);

}

TEST_CASE("(3) one node") {

    avltree<int, int>  avl;
    avl.insert(123, 88);
    vector<int>  keys, values, heights;

    REQUIRE(avl.size() == 1);
    REQUIRE(avl.height() == 0);

    keys = avl.inorder_keys();
    values = avl.inorder_values();
    heights = avl.inorder_heights();

    REQUIRE(keys[0] == 123);
    REQUIRE(values[0] == 88);
    REQUIRE(heights[0] == 0);

}

TEST_CASE("(4) left rotate") {

    avltree<int, int> avl;
    avl.insert(100, -100);
    avl.insert(120, -120);
    avl.insert(140, -140);

    vector<int> keys, values, heights;
    keys = avl.inorder_keys();
    values = avl.inorder_values();
    heights = avl.inorder_heights();

    REQUIRE(avl.size() == 3);
    REQUIRE(avl.height() == 1);

    REQUIRE(keys[0] == 100);
    REQUIRE(values[0] == -100);
    REQUIRE(heights[0] == 0);

    REQUIRE(keys[1] == 120);
    REQUIRE(values[1] == -120);
    REQUIRE(heights[1] == 1);

    REQUIRE(keys[2] == 140);
    REQUIRE(values[2] == -140);
    REQUIRE(heights[2] == 0);   

}

TEST_CASE("(5) right rotate") {

    avltree<int, int> avl;
    avl.insert(100, -100);
    avl.insert(80, -80);
    avl.insert(60, -60);

    vector<int> keys, values, heights;
    keys = avl.inorder_keys();
    values = avl.inorder_values();
    heights = avl.inorder_heights();

    REQUIRE(avl.size() == 3);
    REQUIRE(avl.height() == 1);

    REQUIRE(keys[0] == 60);
    REQUIRE(values[0] == -60);
    REQUIRE(heights[0] == 0);

    REQUIRE(keys[1] == 80);
    REQUIRE(values[1] == -80);
    REQUIRE(heights[1] == 1);

    REQUIRE(keys[2] == 100);
    REQUIRE(values[2] == -100);
    REQUIRE(heights[2] == 0);

}

TEST_CASE("(6) LR rotate") {

    avltree<int, int> avl;
    avl.insert(100, -100);
    avl.insert(60, -60);
    avl.insert(80, -80);

    vector<int> keys, values, heights;
    keys = avl.inorder_keys();
    values = avl.inorder_values();
    heights = avl.inorder_heights();

    REQUIRE(avl.size() == 3);
    REQUIRE(avl.height() == 1);

    REQUIRE(keys[0] == 60);
    REQUIRE(values[0] == -60);
    REQUIRE(heights[0] == 0);

    REQUIRE(keys[1] == 80);
    REQUIRE(values[1] == -80);
    REQUIRE(heights[1] == 1);

    REQUIRE(keys[2] == 100);
    REQUIRE(values[2] == -100);
    REQUIRE(heights[2] == 0);
    
}

TEST_CASE("(6.5) more LR rotate") {

    avltree<int, int> avl;
    avl.insert(100, -100);
    avl.insert(60, -60);
    avl.insert(80, -80);
    avl.insert(65, -65);
    avl.insert(63, -63);
    avl.insert(64, -64);
    avl.insert(90, -90);
    avl.insert(70, -70);
    avl.insert(67, -67);
    avl.insert(69, -69);

    vector<int> keys, values, heights;
    keys = avl.inorder_keys();
    values = avl.inorder_values();
    heights = avl.inorder_heights();

    REQUIRE(avl.size() == 10);
    REQUIRE(avl.height() == 3);

    REQUIRE(values[3] == -65);
    REQUIRE(heights[3] == 3);

    REQUIRE(keys[4] == 67);
    REQUIRE(values[4] == -67);
    REQUIRE(heights[4] == 1);

    REQUIRE(keys[5] == 69);
    REQUIRE(values[5] == -69);
    REQUIRE(heights[5] == 0);

    REQUIRE(keys[6] == 70);
    REQUIRE(values[6] == -70);
    REQUIRE(heights[6] == 2);

    REQUIRE(keys[7] == 80);
    REQUIRE(values[7] == -80);
    REQUIRE(heights[7] == 0);

    REQUIRE(keys[8] == 90);
    REQUIRE(values[8] == -90);
    REQUIRE(heights[8] == 1);

    REQUIRE(keys[9] == 100);
    REQUIRE(values[9] == -100);
    REQUIRE(heights[9] == 0);

}

TEST_CASE("(7) RL rotate") {

    avltree<int, int> avl;
    avl.insert(100, -100);
    avl.insert(140, -140);
    avl.insert(120, -120);

    vector<int> keys, values, heights;
    keys = avl.inorder_keys();
    values = avl.inorder_values();
    heights = avl.inorder_heights();

    REQUIRE(avl.size() == 3);
    REQUIRE(avl.height() == 1);

    REQUIRE(keys[0] == 100);
    REQUIRE(values[0] == -100);
    REQUIRE(heights[0] == 0);

    REQUIRE(keys[1] == 120);
    REQUIRE(values[1] == -120);
    REQUIRE(heights[1] == 1);

    REQUIRE(keys[2] == 140);
    REQUIRE(values[2] == -140);
    REQUIRE(heights[2] == 0);
    
}

TEST_CASE("(8) complicated tree") {

    avltree<int, int> avl;
    avl.insert(100, -100);
    avl.insert(120, -120);
    avl.insert(80, -80);
    avl.insert(140, -140);
    avl.insert(60, -60);
    avl.insert(160, -160);
    avl.insert(40, -40);
    avl.insert(150, -150);
    avl.insert(20, -20);

    vector<int> keys, values, heights;
    keys = avl.inorder_keys();
    values = avl.inorder_values();
    heights = avl.inorder_heights();

    REQUIRE(avl.size() == 9);
    REQUIRE(avl.height() == 3);

    REQUIRE(keys[0] == 20);
    REQUIRE(values[0] == -20);
    REQUIRE(heights[0] == 0);

    REQUIRE(keys[1] == 40);
    REQUIRE(values[1] == -40);
    REQUIRE(heights[1] == 1);

    REQUIRE(keys[2] == 60);
    REQUIRE(values[2] == -60);
    REQUIRE(heights[2] == 2);

    REQUIRE(keys[3] == 80);
    REQUIRE(values[3] == -80);
    REQUIRE(heights[3] == 0);

    REQUIRE(keys[4] == 100);
    REQUIRE(values[4] == -100);
    REQUIRE(heights[4] == 3);

    REQUIRE(keys[5] == 120);
    REQUIRE(values[5] == -120);
    REQUIRE(heights[5] == 0);

    REQUIRE(keys[6] == 140);
    REQUIRE(values[6] == -140);
    REQUIRE(heights[6] == 2);

    REQUIRE(keys[7] == 150);
    REQUIRE(values[7] == -150);
    REQUIRE(heights[7] == 0);

    REQUIRE(keys[8] == 160);
    REQUIRE(values[8] == -160);
    REQUIRE(heights[8] == 1);
   
}

TEST_CASE("(9) AVL tree distance") {

    avltree<int, int>  avl;
    avl.insert(100, -100);
    avl.insert(50, -50);
    avl.insert(150, -150);
    avl.insert(125, -125);

    REQUIRE(avl.distance(50, 100) == 1);
    REQUIRE(avl.distance(100, 100) == 0);
    REQUIRE(avl.distance(50, 125) == 3);
    REQUIRE(avl.distance(125, 150) == 1);
    REQUIRE(avl.distance(125, 50) == 3);
    REQUIRE(avl.distance(150, -500) == -1);
    
}

TEST_CASE("(10) big tree") {

    avltree<int, int> avl;
    avl.insert(100, -100);
    avl.insert(120, -120);
    avl.insert(80, -80);
    avl.insert(140, -140);
    avl.insert(60, -60);
    avl.insert(160, -160);
    avl.insert(40, -40);
    avl.insert(150, -150);
    avl.insert(20, -20);
    avl.insert(45, -100);
    avl.insert(105, -120);
    avl.insert(85, -80);
    avl.insert(145, -140);
    avl.insert(65, -60);
    avl.insert(165, -160);
    avl.insert(35, -40);
    avl.insert(155, -150);
    avl.insert(25, -20);
    avl.insert(95, -100);
    avl.insert(115, -120);
    avl.insert(70, -80);
    avl.insert(135, -140);
    avl.insert(50, -60);
    avl.insert(112, -160);
    avl.insert(15, -40);
    avl.insert(190, -150);
    avl.insert(10, -20);

    REQUIRE(avl.size() == 27);
    REQUIRE(avl.height() == 5);

}