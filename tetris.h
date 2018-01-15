#ifndef TETRIS_H
#define TETRIS_H

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

#include "state.h"
#include "factory.h"
#include "data_player.h"

class Tetris : public QObject, public State
{
		Q_OBJECT

	public:
		Tetris();

		QVector<GameObject *> objects();

		void draw();
		void clearList();
		void mouse(GameWidget*, QMouseEvent*);
		void keyPress(QKeyEvent*);
		void keyRelease(GameWidget*, QKeyEvent*, QTimer*);

	private:
		TetriminoFactory *tetrimino_factory;
		BlockFactory *block_factory;
		TextFactory *text_factory;
		AnimationFactory *animation_factory;

		void setHighscore();

		bool Lose;
		bool Pause;
		int Score;

		QVector<GameObject*> Animations;
		QVector<GameObject*> PlacedTetriminoesMap;
		GameObject *tetrimino,*next, *tnext,*score,*controls,*gamefield, *bckg;
//		QVector<GameObject*> BrickMap;
//		QVector<GameObject*> GreenMap;
//		QVector<GameObject*> WaterMap;
//		QVector<GameObject*> MetallMap;
//		QVector<GameObject*> PlayerCollisions;
//		QVector<GameObject*> EnemyCollisions;
//		QVector<GameObject*> enemies;
//		QVector<GameObject*> players;

		QVector<GameObject*> gameobjects;

//		QVector<GameObject *> BulletsBlocks(QVector <GameObject*>);

		void KillEnemies(GameObject*);
		void YouLose(QVector<GameObject*>);

		int TypeGame;

		template<class T> void quickSortR(T* a, long N)
		{
			long i = 0, j = N;
			T temp, p;

			p = a[ N>>1 ];

			do {
				while ( a[i] < p ) i++;
				while ( a[j] > p ) j--;

				if (i <= j) {
					temp = a[i]; a[i] = a[j]; a[j] = temp;
					i++; j--;
				}
			} while ( i<=j );

			if ( j > 0 ) quickSortR(a, j);
			if ( N > i ) quickSortR(a+i, N-i);
		}

		bool BulletHit;
//		GameObject *animation,*base,*playercontrol,*playerlifes,*lifecounter,*lifecounter1,*score;
//		GameObject *player1,*player2,*bullet1,*enemy1,*enemy2,*enemy3,*block,*gameover,*border;
		int pauser;
};

#endif // TETRIS_H
