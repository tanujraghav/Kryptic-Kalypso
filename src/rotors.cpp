#include "API.h"
using namespace std;

static vector<vector<vector<int>>> data{
    {{114, 179, 98, 194, 123, 204, 230, 224, 203, 21, 180, 252, 235, 88, 162, 55, 15, 37, 96, 36, 243, 58, 236, 223, 209, 205, 93, 157, 50, 129, 153, 199, 30, 195, 227, 215, 207, 200, 239, 174, 176, 38, 138, 183, 250, 124, 151, 69, 9, 225, 226, 0, 47, 51, 254, 159, 135, 105, 171, 147, 23, 218, 212, 245, 34, 92, 253, 191, 170, 28, 141, 70, 122, 75, 97, 214, 66, 247, 237, 208, 192, 113, 91, 172, 142, 117, 234, 201, 56, 29, 78, 126, 43, 121, 79, 186, 241, 120, 148, 233, 166, 128, 107, 173, 197, 248, 76, 240, 112, 118, 177, 246, 238, 193, 119, 198, 2, 219, 109, 164, 57, 19, 41, 160, 190, 77, 25, 130, 59, 217, 53, 32, 94, 145, 110, 108, 82, 106, 100, 18, 220, 80, 150, 167, 95, 72, 185, 152, 158, 64, 73, 81, 35, 163, 90, 46, 169, 74, 1, 244, 13, 211, 11, 149, 12, 54, 115, 7, 127, 71, 184, 45, 6, 33, 161, 221, 228, 44, 111, 206, 85, 86, 42, 139, 10, 16, 61, 22, 104, 143, 251, 84, 155, 133, 134, 14, 68, 213, 60, 140, 99, 168, 249, 187, 202, 20, 52, 27, 102, 181, 188, 131, 232, 26, 210, 231, 196, 31, 87, 49, 156, 154, 24, 17, 65, 175, 116, 5, 136, 189, 39, 3, 101, 216, 63, 8, 48, 83, 255, 242, 165, 40, 144, 67, 229, 89, 62, 4, 178, 132, 137, 125, 103, 222, 146, 182},{21, 162, 131, 129, 89, 139, 99, 75, 144, 91, 0, 121, 119, 37, 169, 187, 50, 3, 104, 237, 123, 247, 233, 163, 15, 242, 253, 74, 76, 45, 90, 182, 166, 207, 125, 183, 13, 218, 173, 108, 100, 30, 25, 81, 249, 224, 115, 18, 16, 59, 4, 236, 61, 240, 80, 63, 212, 83, 53, 28, 66, 67, 140, 26, 1, 185, 71, 42, 20, 167, 77, 172, 248, 221, 229, 213, 43, 88, 171, 228, 95, 225, 177, 146, 56, 143, 5, 78, 110, 178, 55, 204, 150, 72, 189, 86, 113, 155, 175, 191, 51, 60, 12, 252, 254, 87, 7, 210, 227, 243, 203, 62, 153, 116, 223, 122, 151, 124, 217, 141, 102, 152, 84, 211, 133, 170, 49, 82, 65, 232, 246, 132, 165, 201, 235, 117, 34, 48, 234, 251, 215, 41, 54, 206, 193, 190, 44, 92, 180, 120, 160, 231, 107, 36, 134, 64, 46, 98, 186, 126, 222, 196, 19, 23, 135, 157, 27, 245, 24, 114, 138, 73, 145, 39, 8, 105, 195, 226, 17, 156, 118, 136, 6, 52, 230, 38, 2, 205, 200, 198, 194, 216, 181, 220, 159, 9, 164, 137, 208, 112, 244, 85, 219, 199, 127, 147, 188, 40, 176, 96, 128, 47, 158, 161, 97, 29, 250, 184, 148, 57, 94, 33, 197, 31, 241, 11, 79, 101, 179, 168, 149, 209, 255, 70, 14, 106, 202, 109, 103, 154, 214, 174, 68, 93, 58, 238, 10, 192, 22, 69, 130, 111, 35, 142, 239, 32},{120, 183, 16, 221, 157, 184, 68, 55, 174, 187, 207, 129, 144, 6, 139, 168, 191, 179, 130, 192, 135, 240, 211, 95, 241, 62, 40, 102, 9, 244, 125, 18, 164, 181, 93, 153, 66, 84, 154, 233, 198, 44, 182, 149, 254, 136, 203, 222, 197, 141, 64, 138, 122, 69, 152, 97, 213, 14, 166, 236, 180, 53, 177, 26, 132, 82, 65, 4, 110, 80, 121, 32, 7, 111, 223, 45, 54, 155, 156, 20, 119, 96, 3, 24, 161, 151, 19, 112, 208, 33, 43, 228, 12, 8, 163, 162, 195, 215, 189, 58, 127, 252, 87, 42, 105, 56, 90, 201, 142, 227, 50, 255, 47, 210, 25, 232, 27, 134, 100, 225, 70, 247, 51, 251, 235, 158, 186, 81, 86, 118, 202, 246, 116, 109, 230, 57, 88, 103, 199, 74, 224, 10, 188, 220, 30, 128, 253, 229, 79, 206, 85, 160, 117, 29, 131, 46, 173, 185, 78, 113, 239, 172, 60, 170, 178, 108, 204, 15, 145, 238, 37, 59, 67, 89, 99, 92, 175, 146, 5, 243, 13, 137, 171, 209, 49, 63, 123, 205, 176, 107, 22, 17, 248, 217, 115, 61, 219, 242, 245, 35, 48, 38, 165, 94, 101, 193, 200, 190, 28, 124, 73, 106, 218, 140, 0, 83, 34, 77, 133, 234, 214, 231, 41, 21, 169, 148, 76, 36, 52, 167, 104, 250, 11, 143, 75, 98, 196, 226, 126, 71, 150, 39, 1, 114, 147, 216, 23, 249, 91, 194, 72, 159, 237, 212, 31, 2},{121, 105, 210, 97, 232, 138, 199, 79, 218, 29, 229, 102, 7, 22, 63, 141, 88, 98, 73, 202, 145, 208, 70, 151, 195, 238, 59, 57, 50, 183, 147, 75, 162, 212, 222, 206, 104, 107, 92, 137, 61, 211, 166, 68, 248, 41, 113, 109, 39, 36, 117, 255, 0, 89, 240, 150, 10, 25, 172, 94, 111, 96, 110, 49, 223, 135, 31, 167, 239, 143, 118, 201, 231, 106, 233, 20, 224, 230, 91, 4, 33, 3, 157, 225, 148, 56, 236, 186, 69, 159, 60, 164, 133, 182, 175, 149, 5, 188, 44, 154, 126, 251, 194, 161, 252, 114, 198, 196, 156, 99, 34, 205, 101, 125, 78, 38, 86, 178, 127, 204, 24, 27, 170, 181, 168, 228, 247, 234, 136, 47, 66, 177, 112, 53, 192, 8, 18, 40, 190, 52, 140, 215, 15, 216, 51, 82, 226, 241, 76, 174, 30, 108, 119, 139, 207, 180, 214, 254, 16, 87, 14, 191, 169, 6, 242, 62, 67, 123, 158, 93, 185, 72, 134, 48, 179, 2, 81, 43, 203, 253, 122, 11, 80, 13, 120, 217, 165, 37, 249, 12, 219, 152, 100, 171, 144, 23, 130, 235, 220, 189, 221, 197, 90, 237, 77, 193, 245, 71, 65, 184, 19, 200, 246, 187, 142, 153, 64, 17, 243, 131, 129, 146, 9, 173, 58, 155, 45, 116, 124, 1, 32, 83, 74, 54, 85, 95, 160, 227, 103, 163, 84, 35, 244, 128, 21, 209, 42, 132, 55, 213, 26, 250, 115, 28, 176, 46},{218, 71, 220, 111, 138, 76, 22, 242, 251, 124, 179, 194, 210, 153, 54, 164, 14, 93, 32, 68, 224, 92, 201, 37, 87, 114, 127, 183, 3, 28, 234, 12, 67, 80, 177, 229, 243, 49, 250, 29, 147, 240, 146, 128, 158, 97, 209, 53, 190, 204, 109, 202, 100, 182, 94, 135, 245, 99, 163, 253, 192, 55, 181, 157, 41, 86, 39, 221, 188, 212, 208, 63, 136, 0, 98, 144, 24, 169, 161, 106, 255, 70, 110, 228, 60, 145, 156, 178, 85, 237, 10, 222, 168, 23, 25, 74, 170, 230, 95, 18, 166, 104, 9, 73, 66, 215, 189, 77, 30, 61, 4, 38, 216, 193, 40, 139, 219, 205, 244, 184, 108, 62, 90, 51, 42, 102, 171, 35, 176, 27, 137, 231, 121, 26, 159, 200, 118, 19, 248, 122, 211, 239, 21, 82, 203, 6, 142, 64, 84, 206, 247, 59, 89, 150, 52, 65, 115, 131, 58, 46, 252, 185, 141, 180, 165, 238, 233, 175, 149, 225, 162, 1, 241, 172, 34, 81, 103, 13, 7, 69, 120, 50, 83, 56, 151, 96, 198, 20, 48, 134, 78, 129, 101, 113, 88, 223, 132, 236, 154, 123, 126, 133, 47, 33, 36, 232, 187, 174, 43, 31, 214, 143, 17, 91, 2, 130, 191, 119, 199, 197, 167, 112, 117, 79, 148, 45, 213, 155, 16, 152, 57, 186, 235, 107, 105, 8, 75, 5, 246, 249, 254, 207, 15, 226, 125, 116, 217, 227, 160, 11, 72, 195, 44, 173, 140, 196},{38, 253, 170, 249, 56, 218, 136, 13, 81, 169, 89, 59, 234, 24, 133, 79, 43, 145, 137, 161, 172, 230, 235, 58, 45, 126, 97, 151, 102, 116, 185, 112, 71, 110, 190, 16, 50, 125, 20, 157, 240, 222, 175, 160, 94, 6, 141, 77, 124, 242, 108, 64, 80, 152, 37, 216, 132, 3, 91, 49, 54, 35, 9, 150, 60, 99, 18, 162, 41, 127, 68, 171, 214, 65, 180, 117, 244, 114, 0, 52, 39, 238, 93, 164, 174, 109, 215, 255, 27, 187, 5, 207, 53, 40, 196, 92, 239, 146, 229, 167, 61, 179, 135, 72, 122, 168, 139, 205, 192, 158, 236, 178, 47, 130, 86, 195, 155, 33, 186, 183, 95, 149, 66, 177, 115, 1, 103, 51, 70, 78, 57, 121, 63, 128, 198, 156, 105, 8, 90, 191, 228, 62, 176, 252, 31, 202, 223, 251, 221, 107, 30, 29, 182, 25, 246, 245, 75, 231, 119, 206, 22, 254, 23, 98, 243, 204, 129, 104, 111, 76, 11, 209, 48, 154, 188, 83, 248, 189, 46, 219, 32, 147, 173, 67, 10, 210, 159, 134, 28, 181, 232, 197, 217, 21, 165, 233, 69, 118, 226, 113, 193, 123, 143, 42, 96, 224, 7, 55, 138, 199, 153, 212, 131, 101, 211, 74, 208, 241, 140, 220, 34, 163, 201, 87, 85, 200, 120, 36, 184, 250, 144, 44, 225, 100, 17, 213, 26, 15, 237, 14, 19, 166, 4, 142, 227, 194, 247, 203, 88, 106, 2, 148, 73, 82, 12, 84},{16, 239, 70, 245, 228, 39, 22, 67, 161, 106, 241, 136, 224, 199, 89, 220, 88, 189, 229, 236, 140, 213, 46, 204, 11, 176, 99, 212, 121, 25, 206, 179, 47, 24, 187, 207, 134, 65, 146, 164, 163, 240, 30, 158, 0, 57, 149, 12, 118, 108, 97, 200, 49, 247, 177, 139, 60, 195, 77, 222, 175, 7, 86, 125, 251, 182, 91, 113, 3, 123, 244, 178, 202, 235, 242, 28, 165, 144, 72, 221, 215, 66, 120, 138, 87, 230, 142, 104, 92, 100, 156, 253, 76, 153, 219, 188, 94, 162, 157, 166, 205, 29, 95, 59, 105, 250, 52, 148, 137, 183, 238, 248, 159, 42, 8, 9, 196, 173, 255, 96, 216, 51, 37, 170, 171, 193, 69, 75, 185, 90, 234, 110, 68, 211, 82, 6, 160, 35, 58, 84, 116, 114, 155, 226, 209, 254, 83, 19, 218, 243, 127, 145, 227, 26, 115, 237, 54, 38, 174, 18, 43, 191, 132, 152, 40, 98, 14, 34, 197, 217, 55, 15, 48, 232, 186, 198, 190, 27, 126, 119, 135, 10, 79, 85, 122, 71, 101, 252, 208, 33, 41, 63, 150, 231, 194, 56, 168, 73, 181, 246, 4, 23, 5, 53, 103, 210, 141, 45, 13, 233, 133, 201, 111, 102, 184, 172, 80, 143, 203, 32, 147, 225, 31, 21, 154, 107, 214, 117, 20, 180, 36, 192, 167, 112, 223, 44, 50, 78, 74, 130, 17, 81, 249, 93, 169, 62, 131, 124, 128, 61, 1, 151, 2, 109, 64, 129},{63, 204, 42, 0, 78, 25, 58, 126, 244, 44, 93, 167, 140, 209, 53, 181, 70, 139, 233, 7, 54, 113, 226, 16, 220, 239, 240, 88, 3, 246, 146, 222, 92, 210, 232, 189, 46, 111, 202, 18, 72, 36, 24, 4, 217, 212, 197, 238, 183, 177, 169, 26, 43, 112, 154, 134, 86, 117, 87, 103, 201, 245, 94, 152, 47, 22, 132, 62, 99, 98, 225, 29, 157, 80, 75, 2, 252, 15, 234, 214, 192, 66, 33, 123, 182, 149, 122, 124, 65, 82, 20, 242, 60, 213, 14, 114, 61, 131, 121, 135, 64, 23, 8, 71, 248, 118, 193, 48, 37, 11, 190, 164, 142, 1, 155, 230, 89, 171, 107, 243, 191, 125, 96, 166, 100, 199, 12, 143, 156, 69, 130, 50, 224, 109, 38, 172, 161, 59, 31, 187, 144, 101, 150, 158, 108, 179, 195, 76, 227, 180, 205, 228, 173, 49, 186, 10, 51, 45, 27, 198, 77, 148, 208, 83, 250, 160, 84, 21, 105, 73, 254, 216, 81, 219, 68, 35, 133, 110, 223, 194, 32, 85, 241, 255, 215, 147, 127, 9, 39, 203, 163, 200, 165, 236, 34, 52, 129, 159, 90, 30, 91, 138, 5, 237, 188, 221, 151, 206, 28, 176, 137, 55, 115, 13, 104, 145, 119, 74, 229, 231, 79, 235, 153, 128, 253, 116, 120, 207, 178, 175, 95, 251, 17, 196, 19, 136, 184, 211, 56, 97, 218, 185, 168, 6, 174, 162, 40, 57, 249, 102, 141, 67, 170, 106, 41, 247}},{{159, 82, 1, 57, 54, 101, 98, 133, 63, 124, 62, 92, 123, 226, 110, 9, 105, 23, 225, 236, 90, 228, 4, 217, 202, 191, 144, 147, 154, 0, 166, 193, 114, 143, 84, 125, 140, 61, 208, 199, 224, 248, 79, 115, 29, 77, 42, 132, 7, 47, 227, 239, 135, 100, 247, 68, 58, 53, 151, 165, 161, 127, 160, 198, 188, 80, 87, 167, 48, 69, 203, 85, 152, 235, 91, 218, 214, 121, 97, 216, 30, 55, 64, 44, 99, 221, 67, 73, 231, 108, 95, 32, 158, 201, 18, 71, 128, 149, 3, 81, 243, 17, 38, 131, 209, 25, 16, 200, 205, 180, 153, 118, 43, 41, 112, 51, 122, 137, 31, 65, 21, 14, 245, 176, 66, 186, 8, 39, 204, 206, 251, 183, 20, 111, 148, 107, 120, 211, 250, 223, 70, 86, 2, 134, 253, 213, 136, 195, 164, 168, 220, 212, 10, 249, 19, 222, 36, 75, 194, 215, 74, 119, 50, 189, 94, 6, 142, 172, 244, 96, 12, 109, 178, 104, 237, 76, 252, 171, 22, 145, 11, 34, 88, 170, 45, 83, 106, 187, 197, 232, 173, 233, 241, 26, 35, 126, 60, 56, 192, 59, 49, 234, 78, 103, 24, 184, 181, 46, 246, 230, 157, 229, 27, 255, 182, 117, 72, 102, 93, 37, 146, 13, 185, 242, 141, 240, 138, 129, 196, 175, 155, 174, 5, 139, 177, 28, 238, 156, 116, 40, 15, 169, 162, 207, 52, 89, 190, 130, 210, 179, 113, 219, 150, 33, 254, 163},{199, 24, 184, 226, 34, 174, 218, 62, 41, 162, 91, 221, 237, 84, 116, 93, 74, 173, 135, 152, 12, 56, 22, 59, 25, 85, 122, 19, 124, 29, 128, 58, 201, 61, 177, 138, 251, 149, 75, 211, 178, 129, 90, 105, 204, 206, 131, 50, 160, 158, 181, 46, 196, 161, 43, 33, 78, 143, 148, 115, 241, 6, 253, 79, 170, 134, 141, 209, 144, 35, 101, 227, 45, 208, 1, 230, 103, 96, 236, 83, 254, 20, 76, 5, 70, 163, 238, 155, 99, 234, 229, 114, 133, 186, 47, 175, 118, 193, 125, 216, 3, 159, 147, 37, 153, 77, 231, 156, 205, 172, 244, 197, 179, 223, 202, 233, 66, 232, 140, 225, 250, 119, 109, 13, 245, 11, 203, 106, 136, 94, 112, 57, 31, 176, 198, 98, 167, 137, 192, 214, 97, 210, 102, 23, 123, 249, 228, 8, 88, 10, 150, 215, 142, 171, 207, 71, 65, 54, 28, 92, 81, 48, 180, 21, 40, 17, 213, 51, 183, 36, 121, 219, 100, 217, 239, 42, 194, 108, 164, 222, 117, 7, 224, 146, 120, 68, 126, 104, 247, 53, 190, 86, 168, 95, 2, 26, 195, 0, 130, 189, 73, 157, 139, 111, 132, 107, 151, 67, 243, 220, 246, 110, 39, 212, 9, 72, 87, 252, 64, 49, 52, 27, 18, 30, 187, 16, 55, 82, 15, 154, 166, 255, 80, 240, 248, 127, 113, 14, 38, 32, 185, 89, 4, 145, 235, 165, 63, 169, 60, 200, 242, 44, 182, 69, 191, 188199, 24, 184, 226, 34, 174, 218, 62, 41, 162, 91, 221, 237, 84, 116, 93, 74, 173, 135, 152, 12, 56, 22, 59, 25, 85, 122, 19, 124, 29, 128, 58, 201, 61, 177, 138, 251, 149, 75, 211, 178, 129, 90, 105, 204, 206, 131, 50, 160, 158, 181, 46, 196, 161, 43, 33, 78, 143, 148, 115, 241, 6, 253, 79, 170, 134, 141, 209, 144, 35, 101, 227, 45, 208, 1, 230, 103, 96, 236, 83, 254, 20, 76, 5, 70, 163, 238, 155, 99, 234, 229, 114, 133, 186, 47, 175, 118, 193, 125, 216, 3, 159, 147, 37, 153, 77, 231, 156, 205, 172, 244, 197, 179, 223, 202, 233, 66, 232, 140, 225, 250, 119, 109, 13, 245, 11, 203, 106, 136, 94, 112, 57, 31, 176, 198, 98, 167, 137, 192, 214, 97, 210, 102, 23, 123, 249, 228, 8, 88, 10, 150, 215, 142, 171, 207, 71, 65, 54, 28, 92, 81, 48, 180, 21, 40, 17, 213, 51, 183, 36, 121, 219, 100, 217, 239, 42, 194, 108, 164, 222, 117, 7, 224, 146, 120, 68, 126, 104, 247, 53, 190, 86, 168, 95, 2, 26, 195, 0, 130, 189, 73, 157, 139, 111, 132, 107, 151, 67, 243, 220, 246, 110, 39, 212, 9, 72, 87, 252, 64, 49, 52, 27, 18, 30, 187, 16, 55, 82, 15, 154, 166, 255, 80, 240, 248, 127, 113, 14, 38, 32, 185, 89, 4, 145, 235, 165, 63, 169, 60, 200, 242, 44, 182, 69, 191, 188},{228, 252, 232, 184, 133, 147, 186, 144, 146, 198, 191, 253, 171, 203, 151, 136, 243, 150, 255, 227, 229, 193, 149, 134, 166, 155, 234, 175, 221, 230, 129, 207, 178, 210, 216, 187, 219, 199, 162, 130, 152, 241, 177, 135, 172, 208, 249, 157, 145, 204, 200, 140, 215, 128, 160, 169, 131, 223, 205, 245, 188, 213, 153, 163, 202, 239, 137, 237, 185, 224, 196, 154, 240, 226, 180, 170, 174, 148, 138, 201, 159, 197, 194, 250, 182, 183, 211, 220, 179, 217, 142, 141, 244, 236, 173, 132, 176, 235, 158, 222, 242, 139, 212, 218, 231, 254, 225, 247, 214, 165, 189, 190, 251, 233, 206, 156, 246, 168, 181, 161, 143, 192, 164, 238, 167, 248, 209, 195, 53, 30, 39, 56, 95, 4, 23, 43, 15, 66, 78, 101, 51, 91, 90, 120, 7, 48, 8, 5, 77, 22, 17, 14, 40, 62, 71, 25, 115, 47, 98, 80, 54, 119, 38, 63, 122, 109, 24, 124, 117, 55, 75, 12, 44, 94, 76, 27, 96, 42, 32, 88, 74, 118, 84, 85, 3, 68, 6, 35, 60, 110, 111, 10, 121, 21, 82, 127, 70, 81, 9, 37, 50, 79, 64, 13, 49, 58, 114, 31, 45, 126, 33, 86, 102, 61, 108, 52, 34, 89, 103, 36, 87, 28, 99, 57, 69, 106, 73, 19, 0, 20, 29, 104, 2, 113, 26, 97, 93, 67, 123, 65, 72, 41, 100, 16, 92, 59, 116, 107, 125, 46, 83, 112, 1, 11, 105, 18},{164, 184, 190, 155, 189, 144, 138, 152, 234, 162, 250, 183, 196, 199, 253, 132, 176, 254, 128, 165, 172, 195, 241, 245, 180, 157, 225, 235, 238, 221, 163, 200, 174, 223, 220, 154, 135, 182, 204, 159, 129, 185, 175, 208, 139, 141, 231, 237, 153, 186, 171, 252, 246, 247, 230, 203, 193, 173, 158, 149, 236, 251, 192, 178, 219, 198, 169, 216, 232, 209, 207, 137, 229, 217, 202, 213, 227, 233, 156, 244, 222, 211, 177, 140, 242, 205, 167, 218, 166, 147, 143, 248, 226, 181, 239, 133, 210, 130, 214, 146, 136, 187, 151, 191, 243, 142, 197, 179, 131, 145, 160, 255, 168, 188, 228, 206, 249, 194, 212, 161, 201, 215, 170, 224, 134, 240, 148, 150, 18, 40, 97, 108, 15, 95, 124, 36, 100, 71, 6, 44, 83, 45, 105, 90, 5, 109, 99, 89, 126, 59, 127, 102, 7, 48, 35, 3, 78, 25, 58, 39, 110, 119, 9, 30, 0, 19, 88, 86, 112, 66, 122, 50, 20, 57, 32, 42, 16, 82, 63, 107, 24, 93, 37, 11, 1, 41, 49, 101, 113, 4, 2, 103, 62, 56, 117, 21, 12, 106, 65, 13, 31, 120, 74, 55, 38, 85, 115, 70, 43, 69, 96, 81, 118, 75, 98, 121, 67, 73, 87, 64, 34, 29, 80, 33, 123, 26, 92, 76, 114, 72, 54, 46, 68, 77, 8, 27, 60, 47, 28, 94, 125, 22, 84, 104, 79, 23, 52, 53, 91, 116, 10, 61, 51, 14, 17, 111}}
    };

void Enigma::init(){

    for(int i=0;i<3;i++)
        this->rot[i]=data[0][this->rotors[i].first];

    for(int i=0;i<2;i++)
        this->ref[i]=data[1][this->reflectors[i]];
}

void Enigma::rotate(vector<int> &vec,int n){
    vector<int> buff=vec;
    for(int i=0;i<vec.size();i++)
        buff[(vec.size()+i-n)%vec.size()]=vec[i];
    vec=buff;
}

void Enigma::rotate(){
    rotate(this->rot[0],1);
    if(this->rot[0][0]==this->turnpoint[this->rotors[0].first])
        rotate(this->rot[1],1);
    if(this->rot[1][0]==this->turnpoint[this->rotors[1].first]&&this->rot[0][0]==this->turnpoint[this->rotors[0].first])
        rotate(this->rot[2],1);
}

void Enigma::forward(){
    this->pixel=this->rot[0][this->pixel];
    this->pixel=this->rot[1][this->pixel];
    this->pixel=this->rot[2][this->pixel];
    this->pixel=this->ref[0][this->pixel];
}

void Enigma::backward(){
    for(int j=0;j<this->ref[0].size();j++)
        if(this->pixel==this->ref[0][j]){
            this->pixel=j;
            break;
        }
    for(int j=0;j<this->rot[2].size();j++)
        if(this->pixel==this->rot[2][j]){
            this->pixel=j;
            break;
        }
    for(int j=0;j<this->rot[1].size();j++)
        if(this->pixel==this->rot[1][j]){
            this->pixel=j;
            break;
        }
    for(int j=0;j<this->rot[0].size();j++)
        if(this->pixel==this->rot[0][j]){
            this->pixel=j;
            break;
        }
}

void Enigma::substitution(){    
    forward();
    this->pixel=this->ref[1][this->pixel];
    backward();
    rotate();
}