#pragma once
//
//#include <SFML/Graphics.hpp>
//#include <unordered_map>
//#include <string>
//
//struct Animation {
//    std::vector<sf::IntRect> frames; // Array di frame
//    float frameTime; // seconds per frame
//    bool loop;
//};
//
//struct AnimationComponent {
//    std::unordered_map<std::string, Animation> animations; //varie animazioni -> vari array di frame 
//    std::string currentAnimation; //stringa che identifica da animations l'animazione corrente
//    float elapsedTime = 0.0f;   //tempo trascorso dall'inizio dell'animazione
//    int currentFrame = 0;   // frame corrente dell'animazione corrente
//    bool playing = true;    
//
//    void addAnimation(const std::string& name, const Animation& animation) {
//        animations[name] = animation;
//    }
//
//    void play(const std::string& name, bool reset = true) {
//        if (animations.find(name) != animations.end()) {
//            currentAnimation = name;
//            playing = true;
//            if (reset) {
//                currentFrame = 0;
//                elapsedTime = 0.0f;
//            }
//        }
//    }
//
//    void stop() {
//        playing = false;
//    }
//
//    void update(float deltaTime, sf::Sprite& sprite) {
//        if (!playing || animations.find(currentAnimation) == animations.end()) return;
//
//        Animation& anim = animations[currentAnimation];
//        elapsedTime += deltaTime;
//
//        if (elapsedTime >= anim.frameTime) {
//            elapsedTime = 0.0f;
//            currentFrame++;
//            if (currentFrame >= static_cast<int>(anim.frames.size())) {
//                if (anim.loop) {
//                    currentFrame = 0;
//                }
//                else {
//                    currentFrame = static_cast<int>(anim.frames.size()) - 1;
//                    playing = false;
//                }
//            }
//            sprite.setTextureRect(anim.frames[currentFrame]);
//        }
//    }
//};
