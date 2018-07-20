#include "quotefactory.h"

#include <qwt_samples.h>
#include <qwt_date.h>

#include <qvector.h>

typedef struct
{
    int day;

    double open;
    double high;
    double low;
    double close;

} t_Data2010;

static t_Data2010 bmwData[] =
{
    { 3, 31.82, 32.46, 31.82, 32.05 },
    { 4, 31.96, 32.41, 31.78, 32.31 },
    { 5, 32.45, 33.04, 32.36, 32.81 },
    { 6, 32.65, 33.20, 32.38, 33.10 },
    { 7, 33.33, 33.43, 32.51, 32.65 },
    { 10, 32.99, 33.05, 32.11, 32.17 },
    { 11, 32.26, 32.26, 31.10, 31.24 },
    { 12, 31.03, 31.52, 31.01, 31.42 },
    { 13, 31.61, 32.18, 31.50, 31.89 },
    { 14, 32.05, 32.13, 31.36, 31.63 },
    { 17, 31.82, 32.12, 31.43, 32.10 },
    { 18, 32.33, 32.45, 31.65, 32.43 },
    { 19, 32.30, 32.39, 31.67, 31.80 },
    { 20, 32.00, 32.19, 31.16, 31.16 },
    { 21, 31.14, 31.37, 30.32, 30.70 },
    { 24, 30.31, 30.79, 30.05, 30.14 },
    { 25, 30.00, 30.53, 29.40, 30.25 },
    { 26, 29.93, 30.14, 29.38, 29.59 },
    { 27, 29.95, 30.28, 29.49, 29.55 },
    { 28, 29.90, 31.30, 29.85, 30.96 },
    { 31, 30.69, 31.31, 30.56, 31.07 },
    { 32, 31.05, 31.28, 30.58, 31.17 },
    { 33, 31.28, 31.77, 31.01, 31.23 },
    { 34, 31.32, 31.53, 30.21, 30.33 },
    { 35, 30.25, 30.28, 29.43, 29.92 },
    { 38, 30.00, 30.45, 29.33, 29.61 },
    { 39, 29.75, 30.07, 29.35, 29.62 },
    { 40, 29.89, 30.12, 29.55, 29.67 },
    { 41, 29.81, 29.87, 29.02, 29.49 },
    { 42, 29.59, 29.84, 28.28, 29.00 },
    { 45, 29.00, 29.29, 28.46, 28.65 },
    { 46, 28.90, 29.45, 28.60, 29.41 },
    { 47, 29.68, 29.77, 29.35, 29.61 },
    { 48, 29.58, 29.76, 28.45, 29.42 },
    { 49, 29.22, 30.43, 29.01, 30.43 },
    { 52, 30.65, 30.67, 30.06, 30.26 },
    { 53, 30.35, 30.52, 29.53, 29.69 },
    { 54, 29.79, 29.87, 29.18, 29.49 },
    { 55, 29.25, 29.82, 29.06, 29.38 },
    { 56, 29.69, 30.00, 29.55, 29.78 },
    { 59, 30.20, 30.58, 29.95, 30.44 },
    { 60, 30.57, 31.47, 30.49, 31.34 },
    { 61, 31.40, 31.76, 31.08, 31.65 },
    { 62, 31.50, 31.80, 31.34, 31.56 },
    { 63, 31.63, 32.45, 31.63, 32.37 },
    { 66, 32.40, 32.54, 31.81, 31.99 },
    { 67, 31.83, 32.29, 31.58, 32.13 },
    { 68, 32.06, 32.33, 31.81, 32.26 },
    { 69, 32.17, 33.26, 32.16, 32.69 },
    { 70, 32.85, 32.94, 32.44, 32.54 },
    { 73, 32.62, 32.92, 32.54, 32.64 },
    { 74, 32.78, 32.97, 32.55, 32.76 },
    { 75, 32.83, 33.04, 32.45, 32.47 },
    { 76, 32.43, 32.56, 31.98, 32.10 },
    { 77, 32.42, 32.49, 32.02, 32.06 },
    { 80, 31.92, 32.65, 31.87, 32.50 },
    { 81, 32.69, 33.44, 32.61, 33.15 },
    { 82, 33.33, 33.51, 32.92, 33.38 },
    { 83, 33.50, 34.10, 33.49, 34.04 },
    { 84, 33.94, 34.35, 33.81, 34.20 },
    { 87, 34.40, 34.73, 34.01, 34.12 },
    { 88, 34.26, 34.43, 33.71, 33.78 },
    { 89, 33.88, 34.29, 33.78, 34.18 },
    { 90, 35.11, 35.49, 34.97, 35.15 },
    { 95, 35.40, 35.45, 35.15, 35.41 },
    { 96, 35.34, 35.41, 34.77, 34.80 },
    { 97, 34.80, 35.06, 34.44, 34.53 },
    { 98, 34.88, 35.05, 34.64, 34.86 },
    { 101, 35.25, 35.39, 34.99, 35.12 },
    { 102, 35.06, 35.38, 34.88, 35.35 },
    { 103, 35.06, 35.58, 34.88, 35.51 },
    { 104, 35.59, 35.61, 35.09, 35.33 },
    { 105, 35.15, 36.19, 35.15, 35.56 },
    { 108, 35.45, 35.78, 35.10, 35.31 },
    { 109, 36.56, 37.08, 36.41, 36.79 },
    { 110, 36.75, 36.99, 36.37, 36.58 },
    { 111, 36.63, 37.12, 35.93, 36.25 },
    { 112, 36.60, 37.40, 36.33, 37.28 },
    { 115, 37.60, 37.85, 37.26, 37.82 },
    { 116, 37.85, 37.96, 37.06, 37.06 },
    { 117, 36.80, 37.28, 36.14, 36.79 },
    { 118, 36.70, 36.90, 36.19, 36.78 },
    { 119, 36.83, 37.62, 36.70, 37.13 },
    { 122, 37.08, 37.50, 36.72, 37.38 },
    { 123, 37.51, 37.56, 35.38, 35.84 },
    { 124, 36.61, 36.62, 35.42, 35.98 },
    { 125, 35.45, 37.38, 35.45, 36.42 },
    { 126, 35.78, 36.90, 35.05, 35.48 },
    { 129, 36.23, 37.74, 36.20, 37.68 },
    { 130, 36.87, 38.19, 36.73, 38.18 },
    { 131, 37.97, 39.35, 37.74, 39.00 },
    { 132, 39.35, 40.06, 39.15, 39.52 },
    { 133, 39.42, 39.88, 38.46, 38.62 },
    { 136, 38.38, 39.59, 38.25, 38.72 },
    { 137, 39.10, 39.65, 38.90, 39.65 },
    { 138, 38.15, 38.70, 36.97, 37.00 },
    { 139, 37.44, 37.55, 35.43, 36.18 },
    { 140, 36.20, 36.57, 35.28, 36.03 },
    { 143, 36.30, 36.38, 35.41, 36.14 },
    { 144, 35.56, 35.67, 34.64, 35.29 },
    { 145, 35.80, 36.32, 35.50, 35.76 },
    { 146, 36.30, 37.33, 36.06, 37.21 },
    { 147, 37.42, 37.88, 37.02, 37.67 },
    { 150, 37.57, 38.09, 37.49, 37.97 },
    { 151, 37.96, 38.38, 36.98, 38.06 },
    { 152, 37.80, 38.46, 37.37, 38.46 },
    { 153, 39.24, 39.55, 38.94, 39.22 },
    { 154, 39.35, 39.40, 37.82, 38.10 },
    { 157, 37.40, 38.55, 37.40, 38.24 },
    { 158, 38.33, 38.54, 37.31, 37.68 },
    { 159, 37.85, 38.98, 37.76, 38.91 },
    { 160, 38.85, 40.92, 38.68, 40.65 },
    { 161, 40.95, 41.27, 39.72, 40.08 },
    { 164, 40.59, 40.85, 39.56, 39.76 },
    { 165, 39.35, 40.05, 39.34, 39.85 },
    { 166, 40.18, 40.41, 38.80, 39.03 },
    { 167, 38.91, 39.96, 38.74, 39.70 },
    { 168, 39.85, 40.87, 39.82, 40.71 },
    { 171, 41.70, 42.33, 41.43, 41.80 },
    { 172, 41.55, 41.88, 41.06, 41.51 },
    { 173, 41.11, 42.01, 41.07, 41.49 },
    { 174, 41.97, 42.19, 41.25, 41.36 },
    { 175, 41.36, 41.38, 40.22, 40.36 },
    { 178, 40.66, 41.64, 40.36, 41.26 },
    { 179, 40.84, 40.88, 39.87, 39.90 },
    { 180, 40.10, 40.61, 39.80, 40.06 },
    { 181, 39.56, 39.56, 38.08, 38.20 },
    { 182, 38.83, 39.20, 37.79, 37.88 },
    { 185, 38.10, 38.53, 37.91, 38.11 },
    { 186, 38.29, 39.27, 38.29, 39.00 },
    { 187, 38.70, 39.87, 38.62, 39.75 },
    { 188, 39.62, 39.97, 38.87, 38.91 },
    { 189, 39.30, 39.39, 38.60, 39.15 },
    { 192, 39.30, 39.30, 38.87, 38.90 },
    { 193, 39.00, 42.14, 39.00, 42.13 },
    { 194, 42.42, 42.71, 40.99, 41.54 },
    { 195, 41.75, 42.94, 41.36, 42.26 },
    { 196, 42.26, 43.29, 41.80, 42.15 },
    { 199, 41.85, 42.09, 41.17, 41.35 },
    { 200, 42.00, 42.12, 40.60, 41.07 },
    { 201, 41.30, 41.80, 40.61, 40.92 },
    { 202, 40.83, 42.35, 40.79, 41.97 },
    { 203, 41.95, 42.24, 41.58, 41.99 },
    { 206, 42.17, 42.29, 41.61, 42.11 },
    { 207, 42.24, 42.49, 41.21, 41.50 },
    { 208, 41.68, 41.88, 40.41, 40.72 },
    { 209, 40.77, 41.22, 40.40, 40.72 },
    { 210, 40.44, 41.40, 39.96, 41.31 },
    { 213, 41.46, 42.01, 41.02, 41.87 },
    { 214, 42.75, 44.04, 42.75, 43.16 },
    { 215, 43.14, 43.83, 42.49, 43.68 },
    { 216, 43.69, 44.99, 43.47, 44.51 },
    { 217, 44.90, 45.38, 43.72, 43.90 },
    { 220, 44.49, 44.60, 43.97, 44.31 },
    { 221, 44.35, 44.40, 43.15, 43.35 },
    { 222, 43.05, 43.08, 42.33, 42.40 },
    { 223, 42.30, 42.92, 40.78, 41.90 },
    { 224, 42.02, 42.22, 41.28, 41.88 },
    { 227, 42.08, 42.29, 41.40, 41.81 },
    { 228, 41.81, 43.10, 41.74, 43.10 },
    { 229, 43.02, 43.59, 42.76, 43.50 },
    { 230, 43.68, 44.07, 42.66, 42.84 },
    { 231, 42.84, 42.92, 41.74, 41.87 },
    { 234, 42.00, 42.31, 41.60, 41.86 },
    { 235, 41.56, 41.76, 41.10, 41.52 },
    { 236, 41.22, 41.97, 40.83, 41.44 },
    { 237, 41.56, 41.96, 41.35, 41.69 },
    { 238, 41.60, 41.81, 40.74, 41.76 },
    { 241, 41.76, 41.90, 40.94, 41.21 },
    { 242, 40.50, 41.67, 40.15, 41.67 },
    { 243, 42.00, 42.99, 41.38, 42.91 },
    { 244, 42.64, 43.89, 42.64, 43.60 },
    { 245, 43.60, 44.53, 43.26, 44.10 },
    { 248, 44.17, 44.20, 43.47, 44.03 },
    { 249, 43.97, 44.31, 43.51, 43.94 },
    { 250, 43.72, 44.99, 43.60, 44.99 },
    { 251, 44.70, 45.74, 44.51, 45.40 },
    { 252, 45.00, 46.87, 44.99, 46.21 },
    { 255, 46.65, 47.05, 45.91, 46.44 },
    { 256, 46.30, 47.12, 46.21, 47.12 },
    { 257, 46.98, 47.56, 46.88, 47.25 },
    { 258, 47.18, 47.45, 46.82, 47.35 },
    { 259, 47.81, 48.03, 47.10, 47.41 },
    { 262, 47.37, 49.12, 47.22, 49.12 },
    { 263, 48.85, 49.42, 48.45, 48.48 },
    { 264, 48.48, 48.70, 47.57, 48.08 },
    { 265, 48.49, 48.69, 47.49, 48.29 },
    { 266, 48.09, 50.53, 48.03, 50.35 },
    { 269, 50.15, 50.35, 49.60, 50.15 },
    { 270, 49.80, 50.69, 49.31, 50.67 },
    { 271, 51.00, 51.84, 50.64, 51.06 },
    { 272, 50.90, 52.15, 50.50, 51.44 },
    { 273, 51.44, 51.44, 49.12, 49.30 },
    { 276, 49.06, 49.19, 47.92, 48.22 },
    { 277, 48.37, 49.96, 47.82, 49.96 },
    { 278, 49.77, 50.05, 49.13, 49.49 },
    { 279, 49.31, 50.25, 48.81, 50.00 },
    { 280, 50.26, 50.29, 49.42, 50.07 },
    { 283, 50.20, 50.62, 49.82, 49.87 },
    { 284, 49.44, 50.49, 49.06, 50.20 },
    { 285, 50.40, 50.49, 49.88, 50.07 },
    { 286, 50.50, 50.50, 49.74, 50.00 },
    { 287, 50.08, 50.25, 49.19, 49.45 },
    { 290, 49.23, 49.42, 48.58, 49.00 },
    { 291, 48.99, 49.69, 48.84, 49.12 },
    { 292, 49.09, 49.60, 48.90, 49.60 },
    { 293, 49.54, 50.09, 49.31, 50.02 },
    { 294, 50.19, 50.44, 49.54, 50.03 },
    { 297, 50.31, 51.02, 50.20, 50.72 },
    { 298, 50.49, 50.94, 50.12, 50.44 },
    { 299, 50.04, 50.45, 49.10, 49.88 },
    { 300, 50.15, 50.48, 49.53, 49.85 },
    { 301, 49.49, 51.65, 49.44, 51.51 },
    { 304, 51.77, 52.99, 51.65, 52.96 },
    { 305, 52.70, 52.70, 52.10, 52.35 },
    { 306, 50.75, 52.38, 50.65, 51.64 },
    { 307, 52.05, 54.15, 52.00, 54.08 },
    { 308, 54.14, 54.99, 53.76, 54.06 },
    { 311, 53.69, 53.77, 52.86, 53.41 },
    { 312, 53.40, 54.98, 53.22, 54.91 },
    { 313, 54.60, 54.70, 53.33, 53.75 },
    { 314, 54.00, 54.49, 53.60, 54.42 },
    { 315, 53.33, 55.90, 52.85, 55.29 },
    { 318, 55.07, 56.52, 54.90, 56.06 },
    { 319, 55.68, 55.83, 54.62, 54.62 },
    { 320, 54.72, 54.73, 53.87, 54.30 },
    { 321, 54.96, 56.30, 54.94, 56.30 },
    { 322, 56.34, 56.73, 55.65, 56.67 },
    { 325, 57.33, 58.90, 57.30, 57.69 },
    { 326, 57.15, 58.62, 56.39, 56.47 },
    { 327, 57.01, 59.12, 56.48, 59.12 },
    { 328, 59.10, 60.00, 58.84, 59.90 },
    { 329, 59.31, 59.76, 58.13, 59.25 },
    { 332, 59.75, 59.91, 57.74, 57.74 },
    { 333, 57.70, 59.24, 57.22, 57.93 },
    { 334, 58.35, 60.90, 58.35, 60.90 },
    { 335, 61.69, 63.80, 61.55, 63.80 },
    { 336, 63.70, 65.49, 63.48, 63.69 },
    { 339, 64.00, 64.53, 62.75, 62.81 },
    { 340, 63.00, 64.49, 62.40, 63.98 },
    { 341, 63.50, 63.50, 61.90, 61.90 },
    { 342, 62.42, 62.66, 58.88, 60.20 },
    { 343, 60.50, 62.99, 60.39, 62.52 },
    { 346, 62.00, 63.44, 62.00, 63.44 },
    { 347, 63.40, 63.44, 62.14, 62.47 },
    { 348, 62.00, 62.83, 61.40, 62.49 },
    { 349, 62.40, 63.26, 61.79, 62.80 },
    { 350, 62.95, 63.15, 61.80, 61.95 },
    { 353, 61.90, 63.23, 61.64, 63.15 },
    { 354, 63.40, 64.80, 62.92, 64.80 },
    { 355, 64.98, 65.11, 64.30, 64.37 },
    { 356, 64.55, 64.69, 63.24, 63.26 },
    { 360, 62.70, 62.70, 59.12, 59.22 },
    { 361, 59.69, 59.98, 57.66, 58.25 },
    { 362, 58.10, 58.92, 58.08, 58.72 },
    { 363, 59.10, 59.47, 58.62, 58.85 }
};

static t_Data2010 porscheData[] =
{
    { 3, 43.00, 43.96, 42.80, 43.37 },
    { 4, 43.15, 45.00, 43.00, 44.77 },
    { 5, 45.75, 46.50, 45.41, 45.65 },
    { 6, 45.67, 48.56, 45.32, 48.28 },
    { 7, 48.78, 48.81, 47.39, 48.00 },
    { 10, 48.26, 49.18, 47.86, 48.35 },
    { 11, 48.35, 48.65, 46.73, 47.05 },
    { 12, 46.51, 47.65, 46.35, 47.37 },
    { 13, 48.10, 48.70, 47.00, 48.13 },
    { 14, 48.10, 48.20, 46.79, 47.85 },
    { 17, 47.85, 48.57, 47.58, 48.10 },
    { 18, 47.85, 48.00, 46.51, 47.65 },
    { 19, 47.24, 47.62, 45.86, 46.40 },
    { 20, 46.51, 46.61, 44.87, 45.00 },
    { 21, 45.00, 45.11, 42.92, 43.50 },
    { 24, 43.00, 43.83, 42.48, 42.97 },
    { 25, 42.47, 43.37, 41.90, 43.23 },
    { 26, 43.00, 43.00, 41.55, 42.28 },
    { 27, 42.80, 42.83, 41.65, 41.72 },
    { 28, 40.91, 41.50, 40.10, 41.11 },
    { 31, 40.85, 41.85, 40.81, 41.55 },
    { 32, 41.69, 43.16, 41.28, 42.87 },
    { 33, 43.47, 43.53, 42.30, 42.47 },
    { 34, 42.67, 42.85, 40.95, 41.15 },
    { 35, 40.81, 40.82, 39.56, 40.03 },
    { 38, 40.00, 40.94, 38.45, 38.95 },
    { 39, 38.65, 38.95, 37.83, 38.24 },
    { 40, 38.30, 38.65, 37.92, 38.30 },
    { 41, 38.40, 39.88, 37.91, 38.36 },
    { 42, 38.60, 38.84, 36.06, 36.99 },
    { 45, 37.31, 37.58, 35.85, 36.06 },
    { 46, 36.45, 36.78, 35.90, 36.78 },
    { 47, 37.01, 37.84, 36.14, 37.42 },
    { 48, 37.40, 37.73, 36.03, 37.16 },
    { 49, 36.90, 38.00, 36.72, 37.97 },
    { 52, 37.52, 38.12, 37.14, 37.14 },
    { 53, 37.22, 37.53, 36.34, 36.69 },
    { 54, 36.88, 36.93, 35.94, 36.55 },
    { 55, 36.35, 37.06, 35.75, 36.09 },
    { 56, 36.70, 37.05, 36.10, 36.90 },
    { 59, 37.10, 37.74, 36.78, 37.63 },
    { 60, 37.65, 38.58, 37.65, 38.56 },
    { 61, 38.35, 39.60, 38.35, 39.42 },
    { 62, 39.39, 40.15, 39.10, 39.70 },
    { 63, 39.75, 40.60, 39.10, 40.35 },
    { 66, 40.40, 40.40, 39.55, 39.97 },
    { 67, 40.05, 40.10, 39.13, 39.90 },
    { 68, 39.78, 40.55, 39.52, 40.37 },
    { 69, 39.86, 42.53, 39.62, 42.34 },
    { 70, 42.75, 44.73, 42.66, 43.03 },
    { 73, 43.27, 43.49, 42.60, 42.65 },
    { 74, 42.78, 43.78, 42.78, 43.78 },
    { 75, 43.73, 44.00, 42.57, 43.46 },
    { 76, 44.10, 44.51, 43.50, 44.51 },
    { 77, 44.40, 44.70, 44.04, 44.04 },
    { 80, 44.00, 44.05, 43.03, 43.69 },
    { 81, 43.13, 43.51, 42.08, 43.17 },
    { 82, 42.89, 44.71, 42.65, 44.20 },
    { 83, 44.31, 44.47, 43.59, 44.22 },
    { 84, 44.15, 45.15, 44.00, 45.13 },
    { 87, 45.45, 46.10, 45.20, 45.51 },
    { 88, 45.76, 46.10, 44.83, 45.17 },
    { 89, 45.60, 45.60, 44.90, 45.19 },
    { 90, 45.60, 46.46, 45.60, 46.37 },
    { 95, 46.00, 47.44, 46.00, 47.24 },
    { 96, 47.22, 47.48, 45.76, 46.04 },
    { 97, 45.05, 45.55, 44.04, 44.41 },
    { 98, 44.88, 45.44, 44.44, 44.99 },
    { 101, 45.20, 45.57, 44.88, 45.35 },
    { 102, 45.10, 46.03, 45.02, 45.71 },
    { 103, 46.02, 46.60, 45.54, 46.30 },
    { 104, 46.44, 46.60, 45.72, 46.04 },
    { 105, 45.80, 46.35, 44.67, 44.67 },
    { 108, 44.50, 45.17, 43.79, 43.83 },
    { 109, 45.39, 46.00, 44.66, 45.92 },
    { 110, 46.00, 46.46, 45.26, 46.26 },
    { 111, 46.29, 46.64, 44.94, 45.20 },
    { 112, 45.69, 46.22, 45.22, 45.97 },
    { 115, 46.30, 46.71, 45.85, 46.69 },
    { 116, 46.48, 46.48, 45.01, 45.01 },
    { 117, 44.60, 45.03, 42.97, 44.03 },
    { 118, 43.50, 44.38, 42.80, 43.76 },
    { 119, 43.40, 44.33, 42.85, 43.69 },
    { 122, 43.70, 43.70, 42.38, 42.71 },
    { 123, 42.95, 42.95, 40.39, 40.53 },
    { 124, 39.99, 40.15, 38.76, 39.95 },
    { 125, 39.05, 40.25, 37.17, 37.40 },
    { 126, 36.30, 37.25, 34.80, 35.58 },
    { 129, 37.54, 38.19, 37.12, 37.92 },
    { 130, 37.79, 38.08, 37.30, 38.08 },
    { 131, 37.94, 39.99, 37.78, 39.73 },
    { 132, 39.80, 40.20, 39.19, 39.73 },
    { 133, 39.35, 39.40, 36.61, 36.72 },
    { 136, 36.29, 38.48, 36.29, 37.58 },
    { 137, 38.33, 38.58, 37.64, 38.47 },
    { 138, 37.77, 38.42, 36.63, 36.67 },
    { 139, 36.40, 36.67, 33.83, 34.72 },
    { 140, 33.85, 34.69, 32.89, 34.07 },
    { 143, 34.49, 35.03, 33.15, 34.40 },
    { 144, 33.40, 33.42, 32.15, 32.54 },
    { 145, 33.28, 34.19, 32.76, 33.49 },
    { 146, 33.85, 35.77, 33.78, 35.49 },
    { 147, 35.99, 36.35, 35.08, 35.53 },
    { 150, 35.24, 35.81, 35.17, 35.34 },
    { 151, 35.21, 36.10, 34.42, 35.24 },
    { 152, 34.55, 35.20, 34.29, 34.85 },
    { 153, 35.63, 36.09, 35.29, 35.70 },
    { 154, 35.98, 35.98, 34.38, 34.50 },
    { 157, 34.45, 34.65, 32.94, 33.26 },
    { 158, 33.50, 33.65, 31.60, 31.91 },
    { 159, 32.42, 33.29, 32.00, 33.22 },
    { 160, 33.10, 33.97, 32.50, 33.58 },
    { 161, 33.97, 35.12, 33.83, 34.85 },
    { 164, 34.90, 35.70, 34.87, 34.97 },
    { 165, 34.40, 34.58, 32.86, 33.46 },
    { 166, 33.87, 33.87, 32.51, 32.87 },
    { 167, 33.17, 34.65, 32.62, 34.60 },
    { 168, 35.58, 35.64, 34.69, 35.06 },
    { 171, 36.52, 37.19, 36.00, 37.00 },
    { 172, 36.87, 37.48, 36.44, 36.85 },
    { 173, 36.38, 36.98, 36.05, 36.40 },
    { 174, 36.00, 36.50, 34.81, 35.08 },
    { 175, 35.21, 36.24, 34.53, 36.04 },
    { 178, 36.76, 37.24, 36.35, 37.16 },
    { 179, 36.49, 36.88, 35.75, 35.81 },
    { 180, 35.92, 36.28, 35.08, 35.29 },
    { 181, 35.00, 35.00, 33.49, 33.54 },
    { 182, 34.00, 34.40, 33.51, 33.51 },
    { 185, 33.80, 34.14, 33.60, 33.74 },
    { 186, 33.75, 35.79, 33.75, 34.96 },
    { 187, 34.85, 35.88, 34.48, 35.88 },
    { 188, 36.00, 36.64, 35.75, 35.96 },
    { 189, 36.41, 36.80, 35.85, 36.72 },
    { 192, 36.60, 37.22, 36.55, 37.08 },
    { 193, 37.10, 38.47, 37.10, 38.08 },
    { 194, 38.19, 38.35, 37.15, 37.49 },
    { 195, 37.35, 37.81, 36.60, 36.87 },
    { 196, 36.76, 37.22, 36.50, 36.74 },
    { 199, 36.51, 36.83, 35.95, 36.08 },
    { 200, 36.12, 36.35, 35.07, 35.42 },
    { 201, 35.40, 36.30, 34.87, 35.08 },
    { 202, 35.00, 37.66, 34.75, 37.47 },
    { 203, 37.70, 39.50, 37.55, 39.12 },
    { 206, 39.43, 39.46, 38.78, 39.18 },
    { 207, 39.30, 39.56, 38.69, 38.98 },
    { 208, 39.00, 39.19, 38.00, 38.23 },
    { 209, 38.10, 39.42, 37.13, 38.72 },
    { 210, 38.88, 39.38, 38.22, 38.82 },
    { 213, 39.26, 39.50, 38.72, 39.01 },
    { 214, 39.07, 40.04, 38.74, 39.10 },
    { 215, 38.85, 39.76, 38.71, 39.29 },
    { 216, 39.30, 39.99, 39.13, 39.53 },
    { 217, 39.50, 40.00, 38.06, 38.32 },
    { 220, 38.60, 39.55, 38.37, 39.38 },
    { 221, 39.48, 39.58, 38.18, 38.56 },
    { 222, 38.58, 38.58, 37.01, 37.31 },
    { 223, 37.32, 37.78, 36.42, 36.82 },
    { 224, 37.30, 37.30, 36.04, 36.53 },
    { 227, 37.00, 37.31, 36.30, 37.12 },
    { 228, 37.00, 38.17, 36.88, 38.00 },
    { 229, 38.10, 38.65, 37.60, 38.58 },
    { 230, 38.60, 39.25, 37.50, 37.88 },
    { 231, 37.85, 37.93, 36.92, 37.26 },
    { 234, 37.53, 38.09, 36.99, 37.64 },
    { 235, 37.59, 37.59, 36.35, 36.80 },
    { 236, 36.50, 36.88, 35.10, 35.93 },
    { 237, 36.40, 36.75, 36.00, 36.35 },
    { 238, 36.50, 36.96, 35.79, 36.78 },
    { 241, 36.91, 37.62, 36.80, 37.15 },
    { 242, 36.45, 36.78, 36.00, 36.74 },
    { 243, 36.82, 38.55, 36.34, 38.26 },
    { 244, 38.67, 39.39, 38.12, 39.26 },
    { 245, 39.28, 39.53, 38.83, 39.29 },
    { 248, 39.40, 39.49, 39.03, 39.28 },
    { 249, 39.30, 39.30, 38.56, 38.80 },
    { 250, 38.55, 39.04, 38.06, 38.89 },
    { 251, 39.00, 39.03, 38.50, 38.90 },
    { 252, 38.90, 39.43, 38.15, 38.30 },
    { 255, 38.76, 38.76, 37.88, 38.09 },
    { 256, 38.37, 38.60, 37.90, 38.42 },
    { 257, 38.69, 39.13, 38.11, 38.68 },
    { 258, 38.27, 38.46, 37.31, 37.41 },
    { 259, 37.88, 38.10, 37.31, 37.60 },
    { 262, 37.62, 37.75, 37.12, 37.52 },
    { 263, 37.50, 37.50, 36.82, 36.83 },
    { 264, 36.95, 37.33, 36.12, 36.12 },
    { 265, 36.07, 36.15, 34.55, 35.62 },
    { 266, 35.29, 36.61, 35.07, 36.53 },
    { 269, 36.60, 36.94, 36.12, 36.50 },
    { 270, 36.15, 36.15, 35.19, 35.51 },
    { 271, 35.51, 36.30, 35.13, 35.56 },
    { 272, 35.96, 36.85, 35.42, 36.33 },
    { 273, 36.50, 36.83, 36.04, 36.31 },
    { 276, 36.44, 36.51, 34.64, 34.74 },
    { 277, 34.75, 35.10, 34.45, 34.99 },
    { 278, 35.45, 35.45, 35.01, 35.20 },
    { 279, 35.50, 35.50, 34.72, 35.10 },
    { 280, 34.80, 35.33, 34.66, 35.25 },
    { 283, 35.12, 36.47, 35.12, 36.33 },
    { 284, 36.12, 37.65, 35.83, 37.16 },
    { 285, 37.40, 40.35, 37.18, 39.00 },
    { 286, 39.30, 40.75, 39.03, 40.34 },
    { 287, 40.80, 42.35, 40.30, 41.53 },
    { 290, 42.00, 42.80, 41.35, 42.70 },
    { 291, 42.70, 43.16, 38.75, 38.97 },
    { 292, 38.60, 40.00, 37.70, 39.79 },
    { 293, 39.61, 39.79, 38.00, 38.40 },
    { 294, 38.29, 38.29, 37.25, 37.60 },
    { 297, 37.73, 38.39, 37.49, 38.06 },
    { 298, 38.02, 38.19, 37.60, 37.99 },
    { 299, 37.90, 38.36, 37.31, 37.49 },
    { 300, 37.40, 37.81, 37.05, 37.19 },
    { 301, 37.00, 37.29, 35.92, 36.81 },
    { 304, 37.00, 37.21, 36.69, 36.90 },
    { 305, 37.00, 37.19, 36.83, 37.01 },
    { 306, 37.97, 38.08, 37.38, 37.65 },
    { 307, 38.39, 38.96, 38.01, 38.71 },
    { 308, 38.70, 40.38, 38.60, 40.02 },
    { 311, 40.02, 40.77, 40.01, 40.60 },
    { 312, 40.40, 43.71, 40.40, 43.54 },
    { 313, 43.00, 44.04, 41.28, 43.33 },
    { 314, 43.00, 44.54, 43.00, 43.94 },
    { 315, 43.30, 44.55, 42.54, 44.55 },
    { 318, 44.10, 47.18, 44.05, 46.60 },
    { 319, 46.45, 47.84, 45.97, 46.55 },
    { 320, 46.40, 47.57, 46.22, 47.38 },
    { 321, 47.85, 49.12, 47.62, 48.97 },
    { 322, 49.30, 50.00, 47.94, 50.00 },
    { 325, 50.20, 53.75, 50.10, 52.43 },
    { 326, 51.90, 54.94, 50.21, 53.07 },
    { 327, 53.20, 56.41, 53.20, 56.41 },
    { 328, 56.98, 59.63, 56.76, 59.27 },
    { 329, 59.00, 60.20, 53.65, 57.70 },
    { 332, 58.30, 59.40, 55.65, 55.88 },
    { 333, 55.85, 58.80, 54.50, 57.93 },
    { 334, 59.37, 61.72, 58.86, 61.43 },
    { 335, 62.93, 65.00, 62.20, 64.54 },
    { 336, 65.50, 66.50, 63.82, 64.80 },
    { 339, 66.00, 66.50, 65.05, 65.70 },
    { 340, 67.60, 69.88, 67.29, 68.57 },
    { 341, 67.90, 67.99, 63.65, 64.69 },
    { 342, 65.90, 66.18, 61.14, 62.02 },
    { 343, 61.42, 66.11, 61.29, 66.00 },
    { 346, 65.63, 67.60, 65.20, 67.19 },
    { 347, 66.99, 67.08, 65.07, 65.19 },
    { 348, 64.90, 65.66, 63.35, 65.50 },
    { 349, 65.07, 66.10, 63.21, 63.48 },
    { 350, 64.28, 64.72, 61.50, 62.06 },
    { 353, 62.00, 63.54, 61.88, 62.25 },
    { 354, 63.00, 63.80, 62.53, 63.75 },
    { 355, 63.79, 64.94, 63.00, 63.56 },
    { 356, 63.62, 64.25, 62.34, 62.48 },
    { 360, 62.21, 62.40, 57.51, 59.40 },
    { 361, 60.00, 60.81, 59.41, 60.07 },
    { 362, 60.10, 60.65, 60.00, 60.30 },
    { 363, 60.30, 60.51, 59.40, 59.66 }
};

static t_Data2010 daimlerData[] =
{
    { 3, 37.24, 37.60, 36.96, 37.55 },
    { 4, 37.50, 37.56, 36.87, 37.24 },
    { 5, 37.19, 37.33, 36.62, 37.25 },
    { 6, 36.85, 36.95, 36.35, 36.72 },
    { 7, 36.92, 37.15, 36.24, 36.94 },
    { 10, 37.19, 37.67, 37.04, 37.20 },
    { 11, 37.34, 37.40, 36.16, 36.28 },
    { 12, 36.00, 36.38, 35.60, 36.19 },
    { 13, 36.60, 37.19, 36.47, 37.10 },
    { 14, 37.00, 37.26, 36.31, 36.49 },
    { 17, 36.58, 37.25, 36.25, 37.12 },
    { 18, 36.65, 36.87, 35.73, 36.71 },
    { 19, 36.44, 36.52, 35.33, 35.60 },
    { 20, 35.90, 36.17, 34.69, 34.76 },
    { 21, 34.40, 34.66, 33.28, 34.18 },
    { 24, 33.56, 34.08, 33.22, 33.50 },
    { 25, 33.15, 33.95, 32.70, 33.86 },
    { 26, 33.46, 33.58, 32.60, 32.92 },
    { 27, 33.53, 33.80, 32.32, 32.32 },
    { 28, 32.85, 33.97, 32.69, 33.42 },
    { 31, 33.00, 33.74, 32.96, 33.57 },
    { 32, 33.51, 33.88, 32.92, 33.76 },
    { 33, 33.96, 34.95, 33.90, 34.34 },
    { 34, 34.49, 34.69, 33.01, 33.10 },
    { 35, 33.31, 33.31, 32.01, 32.32 },
    { 38, 32.79, 33.54, 32.60, 33.31 },
    { 39, 33.57, 33.85, 32.98, 33.33 },
    { 40, 33.42, 34.10, 33.34, 33.63 },
    { 41, 33.86, 33.90, 32.26, 32.77 },
    { 42, 32.93, 33.21, 31.74, 32.46 },
    { 45, 32.55, 33.11, 31.88, 32.01 },
    { 46, 32.25, 32.69, 31.82, 32.62 },
    { 47, 33.10, 33.47, 32.90, 33.04 },
    { 48, 33.04, 33.35, 29.92, 31.50 },
    { 49, 31.20, 32.32, 30.90, 32.30 },
    { 52, 32.60, 32.62, 31.36, 31.40 },
    { 53, 31.68, 31.90, 31.00, 31.25 },
    { 54, 31.45, 31.49, 30.43, 30.94 },
    { 55, 30.75, 31.23, 30.10, 30.35 },
    { 56, 30.56, 31.09, 30.26, 30.66 },
    { 59, 31.15, 31.55, 30.74, 31.34 },
    { 60, 31.40, 32.06, 31.24, 31.75 },
    { 61, 31.49, 32.25, 31.42, 31.95 },
    { 62, 31.75, 32.29, 31.57, 31.91 },
    { 63, 32.01, 33.10, 32.01, 32.99 },
    { 66, 32.97, 33.20, 32.73, 33.01 },
    { 67, 32.90, 32.99, 32.25, 32.76 },
    { 68, 32.83, 33.26, 32.58, 33.12 },
    { 69, 32.88, 33.56, 32.88, 33.19 },
    { 70, 33.20, 33.60, 33.03, 33.53 },
    { 73, 33.65, 33.83, 33.31, 33.33 },
    { 74, 33.60, 34.26, 33.51, 34.11 },
    { 75, 34.49, 34.60, 33.93, 34.35 },
    { 76, 34.35, 34.78, 34.17, 34.64 },
    { 77, 34.60, 34.89, 34.26, 34.38 },
    { 80, 34.19, 34.56, 33.92, 34.40 },
    { 81, 34.49, 34.74, 34.10, 34.45 },
    { 82, 34.55, 34.65, 33.78, 34.49 },
    { 83, 34.63, 35.19, 34.50, 35.01 },
    { 84, 34.85, 35.34, 34.78, 34.98 },
    { 87, 35.27, 35.53, 34.85, 34.95 },
    { 88, 35.28, 35.35, 34.34, 34.56 },
    { 89, 34.73, 34.99, 34.43, 34.85 },
    { 90, 35.08, 35.49, 35.06, 35.40 },
    { 95, 35.52, 35.84, 35.26, 35.51 },
    { 96, 35.60, 35.85, 35.28, 35.42 },
    { 97, 35.29, 35.36, 34.79, 35.18 },
    { 98, 35.50, 35.69, 35.10, 35.36 },
    { 101, 35.68, 35.74, 35.10, 35.41 },
    { 102, 35.43, 36.05, 34.98, 36.00 },
    { 103, 36.25, 36.74, 36.00, 36.67 },
    { 104, 36.80, 36.90, 36.19, 36.72 },
    { 105, 36.74, 37.38, 36.30, 36.54 },
    { 108, 36.49, 36.76, 36.12, 36.31 },
    { 109, 38.80, 39.24, 38.48, 39.00 },
    { 110, 39.06, 39.30, 38.38, 38.45 },
    { 111, 38.46, 38.96, 37.72, 37.85 },
    { 112, 38.21, 39.11, 37.81, 38.87 },
    { 115, 39.26, 39.52, 38.75, 39.47 },
    { 116, 39.26, 39.90, 37.93, 37.93 },
    { 117, 37.92, 38.18, 36.82, 37.76 },
    { 118, 37.85, 39.00, 37.68, 38.79 },
    { 119, 38.80, 39.30, 38.37, 38.81 },
    { 122, 38.31, 38.83, 38.08, 38.62 },
    { 123, 38.87, 38.88, 37.00, 37.37 },
    { 124, 37.72, 37.72, 36.60, 37.02 },
    { 125, 36.84, 37.74, 36.63, 36.93 },
    { 126, 36.25, 36.96, 35.30, 35.85 },
    { 129, 36.75, 38.01, 36.63, 38.01 },
    { 130, 37.33, 38.74, 37.17, 38.65 },
    { 131, 38.35, 40.17, 38.07, 39.79 },
    { 132, 40.20, 41.54, 40.02, 41.37 },
    { 133, 41.00, 41.38, 40.15, 40.58 },
    { 136, 40.21, 41.54, 40.01, 41.08 },
    { 137, 41.32, 41.92, 40.88, 41.92 },
    { 138, 41.40, 41.85, 39.85, 40.20 },
    { 139, 40.60, 40.64, 37.37, 38.40 },
    { 140, 38.15, 38.95, 37.11, 38.83 },
    { 143, 39.00, 39.13, 37.38, 38.49 },
    { 144, 37.26, 37.56, 36.67, 37.19 },
    { 145, 37.50, 38.87, 37.50, 38.24 },
    { 146, 38.60, 40.18, 38.60, 39.94 },
    { 147, 40.55, 40.67, 39.95, 40.30 },
    { 150, 40.35, 41.08, 40.31, 41.00 },
    { 151, 40.75, 41.43, 40.02, 40.99 },
    { 152, 40.50, 40.99, 39.97, 40.78 },
    { 153, 41.75, 41.99, 41.12, 41.26 },
    { 154, 41.55, 41.66, 39.87, 40.38 },
    { 157, 39.65, 40.61, 39.54, 40.08 },
    { 158, 40.15, 40.41, 39.47, 40.24 },
    { 159, 40.60, 42.05, 40.38, 41.94 },
    { 160, 41.72, 43.74, 41.64, 43.26 },
    { 161, 43.44, 43.88, 42.14, 42.74 },
    { 164, 43.20, 43.36, 42.38, 42.52 },
    { 165, 42.00, 42.79, 41.72, 42.33 },
    { 166, 42.46, 42.60, 40.78, 41.14 },
    { 167, 41.00, 42.44, 40.94, 42.31 },
    { 168, 42.47, 43.39, 42.35, 43.12 },
    { 171, 44.07, 44.79, 44.03, 44.50 },
    { 172, 44.15, 44.49, 43.74, 44.47 },
    { 173, 43.92, 44.65, 43.78, 43.95 },
    { 174, 44.49, 44.69, 43.25, 43.42 },
    { 175, 42.98, 42.98, 41.74, 42.01 },
    { 178, 42.14, 43.36, 41.86, 43.24 },
    { 179, 42.50, 42.72, 41.07, 41.28 },
    { 180, 41.62, 42.49, 41.32, 41.92 },
    { 181, 41.47, 41.82, 40.17, 40.42 },
    { 182, 40.90, 41.49, 40.17, 40.28 },
    { 185, 40.56, 40.85, 39.95, 39.95 },
    { 186, 40.15, 41.95, 40.15, 41.21 },
    { 187, 41.00, 41.99, 40.56, 41.94 },
    { 188, 42.01, 42.33, 41.15, 41.58 },
    { 189, 41.80, 41.97, 41.39, 41.63 },
    { 192, 41.80, 41.95, 41.38, 41.56 },
    { 193, 41.40, 43.81, 41.40, 43.81 },
    { 194, 44.03, 44.48, 43.06, 43.54 },
    { 195, 43.47, 44.35, 42.82, 43.28 },
    { 196, 43.39, 44.70, 42.94, 43.05 },
    { 199, 43.04, 43.22, 42.20, 42.63 },
    { 200, 42.65, 42.88, 41.30, 41.42 },
    { 201, 41.63, 42.05, 40.72, 40.96 },
    { 202, 40.79, 42.51, 40.76, 42.26 },
    { 203, 42.03, 42.83, 41.74, 42.49 },
    { 206, 42.74, 43.17, 42.36, 43.15 },
    { 207, 43.18, 43.38, 40.81, 41.34 },
    { 208, 41.90, 41.97, 41.27, 41.47 },
    { 209, 41.60, 42.11, 41.13, 41.44 },
    { 210, 41.31, 41.67, 40.79, 41.38 },
    { 213, 41.14, 41.58, 40.64, 41.40 },
    { 214, 41.33, 42.10, 41.33, 42.00 },
    { 215, 41.90, 42.10, 41.48, 41.68 },
    { 216, 41.63, 42.44, 41.56, 42.12 },
    { 217, 42.43, 42.75, 40.84, 40.97 },
    { 220, 41.53, 41.99, 41.10, 41.97 },
    { 221, 41.79, 41.79, 40.84, 41.22 },
    { 222, 40.85, 40.97, 39.92, 40.19 },
    { 223, 40.01, 40.40, 38.53, 39.07 },
    { 224, 39.48, 39.90, 38.89, 39.15 },
    { 227, 39.41, 40.14, 39.23, 39.96 },
    { 228, 40.26, 41.10, 40.13, 41.05 },
    { 229, 40.87, 41.10, 40.50, 40.62 },
    { 230, 40.97, 41.22, 39.65, 39.88 },
    { 231, 39.71, 39.95, 39.10, 39.23 },
    { 234, 39.18, 39.53, 38.90, 39.15 },
    { 235, 38.94, 39.05, 38.17, 38.66 },
    { 236, 38.46, 38.82, 37.64, 38.29 },
    { 237, 38.50, 38.63, 37.85, 38.08 },
    { 238, 37.99, 38.40, 37.60, 38.40 },
    { 241, 38.55, 38.83, 37.77, 38.12 },
    { 242, 37.50, 38.36, 37.03, 38.36 },
    { 243, 38.50, 40.49, 38.30, 40.46 },
    { 244, 40.29, 41.42, 40.22, 41.00 },
    { 245, 41.06, 42.24, 40.94, 41.65 },
    { 248, 41.72, 41.86, 41.08, 41.25 },
    { 249, 40.99, 41.36, 40.65, 41.35 },
    { 250, 41.25, 42.06, 41.12, 42.00 },
    { 251, 41.99, 43.15, 41.79, 43.08 },
    { 252, 43.00, 44.02, 42.86, 43.78 },
    { 255, 44.31, 44.65, 43.66, 43.67 },
    { 256, 43.57, 44.20, 43.54, 44.15 },
    { 257, 44.09, 44.49, 43.94, 44.12 },
    { 258, 43.70, 44.22, 43.62, 44.06 },
    { 259, 44.30, 44.74, 43.62, 44.47 },
    { 262, 44.47, 45.50, 44.35, 45.50 },
    { 263, 45.38, 45.90, 45.26, 45.63 },
    { 264, 45.01, 45.19, 44.23, 44.85 },
    { 265, 44.83, 45.13, 43.78, 44.35 },
    { 266, 44.08, 46.17, 44.00, 46.13 },
    { 269, 46.12, 46.69, 45.85, 46.41 },
    { 270, 46.25, 46.64, 45.55, 46.23 },
    { 271, 46.38, 46.85, 46.01, 46.28 },
    { 272, 45.98, 47.59, 45.88, 46.46 },
    { 273, 46.32, 46.86, 45.11, 45.51 },
    { 276, 45.19, 45.19, 43.66, 43.78 },
    { 277, 43.74, 44.88, 43.59, 44.69 },
    { 278, 45.05, 45.19, 44.03, 44.24 },
    { 279, 44.50, 45.49, 44.19, 45.37 },
    { 280, 45.20, 45.61, 44.62, 45.44 },
    { 283, 45.65, 46.30, 45.45, 45.92 },
    { 284, 46.02, 47.73, 45.66, 47.42 },
    { 285, 47.80, 48.21, 47.22, 47.94 },
    { 286, 48.00, 48.04, 47.17, 47.40 },
    { 287, 47.50, 48.13, 47.18, 47.72 },
    { 290, 47.64, 48.10, 47.24, 47.78 },
    { 291, 47.50, 47.80, 46.86, 47.04 },
    { 292, 46.80, 47.90, 46.75, 47.80 },
    { 293, 47.66, 49.12, 47.65, 49.03 },
    { 294, 48.97, 49.51, 48.63, 49.31 },
    { 297, 49.70, 50.05, 49.37, 49.70 },
    { 298, 49.22, 49.56, 48.30, 48.74 },
    { 299, 48.40, 49.10, 47.53, 47.62 },
    { 300, 48.10, 49.05, 46.74, 46.98 },
    { 301, 46.76, 47.73, 46.35, 47.43 },
    { 304, 48.10, 48.37, 47.33, 47.65 },
    { 305, 47.42, 48.62, 47.22, 48.41 },
    { 306, 48.50, 49.15, 48.10, 48.34 },
    { 307, 49.10, 50.14, 48.80, 50.00 },
    { 308, 50.08, 50.45, 48.85, 48.94 },
    { 311, 49.08, 49.10, 48.52, 48.94 },
    { 312, 48.72, 50.28, 48.65, 50.04 },
    { 313, 49.76, 49.91, 48.70, 49.17 },
    { 314, 49.56, 49.75, 48.98, 49.56 },
    { 315, 48.60, 50.23, 47.92, 49.88 },
    { 318, 49.26, 51.40, 49.26, 50.89 },
    { 319, 50.50, 50.93, 49.47, 49.47 },
    { 320, 49.46, 49.69, 48.98, 49.27 },
    { 321, 50.04, 50.96, 49.80, 50.81 },
    { 322, 50.88, 51.00, 50.18, 50.74 },
    { 325, 50.99, 51.59, 50.31, 50.56 },
    { 326, 50.16, 51.26, 49.51, 49.51 },
    { 327, 50.12, 52.04, 49.73, 52.04 },
    { 328, 52.00, 52.63, 51.52, 51.93 },
    { 329, 51.47, 51.93, 50.65, 51.54 },
    { 332, 51.93, 52.06, 49.79, 49.79 },
    { 333, 50.00, 50.93, 49.01, 49.87 },
    { 334, 50.51, 51.96, 50.09, 51.94 },
    { 335, 52.30, 53.64, 51.88, 53.49 },
    { 336, 53.00, 54.78, 52.68, 53.95 },
    { 339, 53.95, 54.18, 53.40, 53.62 },
    { 340, 53.68, 54.37, 52.61, 54.15 },
    { 341, 53.84, 54.05, 52.97, 53.26 },
    { 342, 53.85, 54.14, 52.15, 53.30 },
    { 343, 53.54, 54.93, 53.35, 54.87 },
    { 346, 55.00, 55.00, 54.42, 54.76 },
    { 347, 54.50, 54.87, 53.72, 54.11 },
    { 348, 53.81, 54.20, 53.17, 53.90 },
    { 349, 53.71, 54.58, 53.71, 54.41 },
    { 350, 54.07, 54.48, 53.57, 53.68 },
    { 353, 53.88, 54.50, 53.78, 53.88 },
    { 354, 54.02, 54.94, 53.95, 54.66 },
    { 355, 54.70, 55.05, 54.33, 54.33 },
    { 356, 54.30, 54.52, 54.04, 54.07 },
    { 360, 53.30, 53.45, 51.29, 51.57 },
    { 361, 51.67, 51.84, 51.02, 51.50 },
    { 362, 51.50, 51.62, 51.23, 51.32 },
    { 363, 51.50, 51.70, 50.61, 50.73 }
};

QVector<QwtOHLCSample> QuoteFactory::samples2010( Stock stock )
{
    const t_Data2010 *data = NULL;
    int numSamples = 0;

    switch( stock )
    {
        case BMW:
        {
            data = bmwData;
            numSamples = sizeof( bmwData ) / sizeof( t_Data2010 );
            break;
        }
        case Daimler:
        {
            data = daimlerData;
            numSamples = sizeof( daimlerData ) / sizeof( t_Data2010 );
            break;
        }
        case Porsche:
        {
            data = porscheData;
            numSamples = sizeof( porscheData ) / sizeof( t_Data2010 );
            break;
        }
        default:
            break;
    }

    QVector<QwtOHLCSample> samples;
    samples.reserve( numSamples );

    QDateTime year2010( QDate( 2010, 1, 1 ), QTime( 0, 0 ), Qt::UTC );

    for ( int i = 0; i < numSamples; i++ )
    {
        const t_Data2010 &ohlc = data[ i ];

        samples += QwtOHLCSample( 
            QwtDate::toDouble( year2010.addDays( ohlc.day ) ),
            ohlc.open, ohlc.high, ohlc.low, ohlc.close );
    }

    return samples;
}

QString QuoteFactory::title( Stock stock )
{
    switch( stock )
    {
        case BMW:
            return "BMW";
        case Daimler:
            return "Daimler";
        case Porsche:
            return "Porsche";
        default:
            break;
    }

    return "Unknown";
}
