#include "SceneObject.h"

#pragma once

namespace TicTacToe {

    class Game
    {
        SceneObject rootObject;

    public: 
        Game();

        SceneObject& GetRootObject() 
        {
            return rootObject;
        }

        void Run();

    protected:
        void Init();

        void Update();

        void Draw();

        void Shutdown();

//
//        public virtual void OnUpdate(float deltaTime)
//        {
//
//        }
//
//        public virtual void Update()
//        {
//            //update the root object
//            //this will auto update all children
//            rootObject.Update(deltaTime);
//
//            // Call virtual function so it can be overidden
//            OnUpdate(deltaTime);
//        }
//
//        public virtual void Draw()
//        {
//            BeginDrawing();
//
//            ClearBackground(Color.BEIGE);
//
//            DrawText(fps.ToString(), 10, 10, 14, Color.RED);
//
//            rootObject.Draw();
//
//            EndDrawing();
//        }
//
//    }
//}
    };
}



