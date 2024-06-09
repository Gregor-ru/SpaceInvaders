#pragma once
#include "spaceship.hpp"
#include "obstacle.hpp"
#include "alien.hpp"
#include "mysteryship.hpp"

class Game {
    public:
        Game();
        ~Game();
        void Draw();
        void Update();
        void HandleInput();
        char* GetLevelText();
        bool run;
        bool stop;
        int lives;
        int score;
        int highscore;
        int level;
    private:
        void DeleteInactiveLasers();
        std::vector<Obstacle> CreateObstacles();
        std::vector<Alien> CreateAliens();
        void MoveAliens();
        void MoveDownAliens(int distance); 
        void AlienShootLaser();
        void CheckForCollisions();
        void GameOver();
        void Reset();
        void InitGame(int score_now);
        void UpdateLevel();
        void checkForHighscore();
        void saveHighscoreToFile(int highscore);
        int loadHighscoreFromFile();
        Spaceship spaceship;
        std::vector<Obstacle> obstacles;
        std::vector<Alien> aliens;
        int aliensDirection;
        std::vector<Laser> alienLasers;
        constexpr static float alienLaserShootInterval = 0.5;
        float timeLastAlienFired;
        MysteryShip mysteryship;
        float mysteryShipSpawnInterval;
        float timeLastSpawn;
        Vector2 endLine;
};