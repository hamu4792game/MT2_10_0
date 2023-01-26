﻿#include <Novice.h>
#include "Vec2.h"

const char* kWindowTitle = "MT2_10_00_advanced";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR lpCmdLine, _In_ int nShowCmd) {

	// ライブラリの初期化
	int kWindowWidth = 1280, kWindowHeight = 720;
	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	//	分割数
	const int MAX_SPLIT = 16;

	//	
	Vec2 p0 = { 100.0f,100.0f };
	Vec2 p1 = { 400.0f,400.0f };
	Vec2 p2 = { 700.0f,100.0f };
	Vec2 p3 = { 1000.0f,200.0f };
	float rad = 10.0f;

	float t0 = 0.0f;
	float t1 = 0.0f;

	Vec2 catmullRom[6] = { 0.0f,0.0f };

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		for (int i = 0; i < MAX_SPLIT; i++)
		{
			t0 = static_cast<float>(i) / static_cast<float>(MAX_SPLIT);
			t1 = static_cast<float>(i + 1) / static_cast<float>(MAX_SPLIT);
			//	p0～p1
			catmullRom[0] = CatmullRom(p0, p0, p1, p2, t0);
			catmullRom[1] = CatmullRom(p0, p0, p1, p2, t1);
			//	p1～p2
			catmullRom[2] = CatmullRom(p0, p1, p2, p3, t0);
			catmullRom[3] = CatmullRom(p0, p1, p2, p3, t1);
			//	p2～p3
			catmullRom[4] = CatmullRom(p1, p2, p3, p3, t0);
			catmullRom[5] = CatmullRom(p1, p2, p3, p3, t1);

			//	p0～p1
			Novice::DrawLine(static_cast<int>(Change(catmullRom[0]).x), static_cast<int>(Change(catmullRom[0]).y),
				static_cast<int>(Change(catmullRom[1]).x), static_cast<int>(Change(catmullRom[1]).y), 0x0000ffff);
			//	p1～p2
			Novice::DrawLine(static_cast<int>(Change(catmullRom[2]).x), static_cast<int>(Change(catmullRom[2]).y),
				static_cast<int>(Change(catmullRom[3]).x), static_cast<int>(Change(catmullRom[3]).y), 0x0000ffff);
			//	p2～p3
			Novice::DrawLine(static_cast<int>(Change(catmullRom[4]).x), static_cast<int>(Change(catmullRom[4]).y),
				static_cast<int>(Change(catmullRom[5]).x), static_cast<int>(Change(catmullRom[5]).y), 0x0000ffff);
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		Novice::DrawLine(200, 0, 200, 720, 0x00ff00ff);
		Novice::DrawLine(0, 520, 1280, 520, 0xff0000ff);
		Novice::DrawEllipse(Change(p0).x, Change(p0).y, rad, rad, 0.0f, 0xffffffff, kFillModeSolid);
		Novice::DrawEllipse(Change(p1).x, Change(p1).y, rad, rad, 0.0f, 0xffffffff, kFillModeSolid);
		Novice::DrawEllipse(Change(p2).x, Change(p2).y, rad, rad, 0.0f, 0xffffffff, kFillModeSolid);
		Novice::DrawEllipse(Change(p3).x, Change(p3).y, rad, rad, 0.0f, 0xffffffff, kFillModeSolid);

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
