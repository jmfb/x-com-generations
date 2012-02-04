#pragma once

namespace XCom
{

static const unsigned long GAME_WIDTH = 320;
static const unsigned long GAME_HEIGHT = 200;

static const unsigned long SCALE_FACTOR = 3;
static const unsigned long CLIENT_WIDTH = SCALE_FACTOR * GAME_WIDTH;
static const unsigned long CLIENT_HEIGHT = SCALE_FACTOR * GAME_HEIGHT;

static const unsigned long CURSOR_WIDTH = 9;
static const unsigned long CURSOR_HEIGHT = 13;
static const unsigned long CURSOR_SIZE = CURSOR_WIDTH * CURSOR_HEIGHT;

static const unsigned long COLOR_BYTES = 3;

}
