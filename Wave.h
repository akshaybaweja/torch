uint16_t wave() {
  static byte rotation = 3;

  static const uint8_t scaleWidth = 256 / MATRIX_WIDTH;
  static const uint8_t scaleHeight = 256 / MATRIX_HEIGHT;

  static const uint8_t maxX = MATRIX_WIDTH - 1;
  static const uint8_t maxY = MATRIX_HEIGHT - 1;

  static uint8_t waveCount = 1;
  static uint8_t hue = 1;
  static uint8_t theta = 0;

//  EVERY_N_SECONDS(10) {
//    rotation = random(0, 1);
//    waveCount = random(1, 3);
//  }

  int n = 0;

  gPalette = OceanColors_p;

  switch (rotation) {
    case 0:
      for (int x = 0; x < MATRIX_WIDTH; x++) {
        n = quadwave8(x * 2 + theta) / scaleHeight;
        leds[XY(x, n)] = ColorFromPalette(gPalette, x + hue);
        if (waveCount == 2)
          leds[XY(x, maxY - n)] = ColorFromPalette(gPalette, x + hue);
      }
      break;
  
    case 1:
      for (int y = 0; y < MATRIX_HEIGHT; y++) {
        n = quadwave8(y * 2 + theta) / scaleWidth;
        leds[XY(n, y)] = ColorFromPalette(gPalette, y + hue);
        if (waveCount == 2)
          leds[XY(maxX - n, y)] = ColorFromPalette(gPalette, y + hue);
      }
      break;
  
    case 2:
      for (int x = 0; x < MATRIX_WIDTH; x++) {
        n = quadwave8(x * 2 - theta) / scaleHeight;
        leds[XY(x, n)] = ColorFromPalette(gPalette, x + hue);
        if (waveCount == 2)
          leds[XY(x, maxY - n)] = ColorFromPalette(gPalette, x + hue);
      }
      break;
  
    case 3:
      for (int y = 0; y < MATRIX_HEIGHT; y++) {
        n = quadwave8(y * 2 - theta) / scaleWidth;
        leds[XY(n, y)] = ColorFromPalette(gPalette, y + hue);
        if (waveCount == 2)
          leds[XY(maxX - n, y)] = ColorFromPalette(gPalette, y + hue);
      }
      break;
  }

  dimAll(254);

  EVERY_N_MILLISECONDS(10) {
    theta++;
    hue++;
  }

  return 0;
}
