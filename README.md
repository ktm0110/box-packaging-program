# Box Packaging Program

> **A program that calculates the minimum size of a box capable of containing two 3D boxes**

C 언어를 사용하여 **두 개의 3차원 박스(Box)** 를 생성하고,
이 두 박스를 모두 담을 수 있는 **가장 작은 포장 박스**를 계산하는 프로그램입니다.
본 프로젝트는 **포인터, 동적 메모리 할당, 배열, 3차원 구조 이해**를 목표로 합니다.

---

## Project Information

* **Project Type**: OpenSource Basic Project
* **Language**: C
* **Topic**: Box Packaging System
* **Graphics**: OpenGL (시각화 구현 경험 포함)

---

## Project Objective

* 랜덤으로 생성된 **두 개의 3D 박스**를 생성
* 박스의 **가로 / 세로 / 높이**를 고려하여
* 두 박스를 모두 담을 수 있는 **최소 크기의 포장 박스 계산**
* 메모리 구조와 포인터 개념을 실제 문제에 적용

---

## Key Concepts Used

* 완료 **Pointer**
* 완료 **Dynamic Memory Allocation**
* 완료 **Pointer Array**
* 완료 **3D Structure Design**
* 완료 **Random Box Generation**
* 완료 **Step-by-step Face Output**
* 완료 **Basic OpenGL Visualization**

---

## Core Features

### Random Box Generation

* 두 개의 박스를 **랜덤한 크기**로 생성
* 각 박스는 3차원 구조 (Width, Height, Depth)

### Dynamic Memory Allocation

* 박스 및 배열을 **동적 할당**
* 포인터를 이용한 메모리 접근 및 관리

### Pointer Array

* 박스 정보를 **포인터 배열**로 관리
* 다중 객체 처리 연습

### 3D Box Composition

* 박스를 3차원 형태로 구성
* 각 면(face)을 기준으로 출력

### Minimum Packaging Box Calculation

* 두 박스를 모두 포함할 수 있는
* **가장 작은 외부 박스 크기 계산**

---

## Development Progress

| Test   | Description                      | Status      |
| ------ | -------------------------------- | --------- |
| Test 1 | Random box generation            | Completed |
| Test 2 | Array creation                   | Completed |
| Test 3 | Width / Height / Depth selection | Completed |
| Test 4 | Pointer array creation           | Completed |

---

## Example Workflow

1. 랜덤한 크기의 박스 2개 생성
2. 각 박스의 가로·세로·높이 계산
3. 포인터 배열에 박스 정보 저장
4. 두 박스를 포함할 최소 박스 크기 계산
5. 각 면(face) 단위로 출력
6. (Optional) OpenGL을 이용한 시각화

<img width="256" height="239" alt="예시1" src="https://github.com/user-attachments/assets/bd7b83e7-b5d1-4ce6-bcab-07234051efb1" />
<img width="496" height="507" alt="예시2" src="https://github.com/user-attachments/assets/2e6768fe-82a2-4dc5-ab09-ecd088116e73" />

---

## Repository Structure

```text
box-packaging-program/
├── src/
│   ├── main.c
│   ├── box.c
│   └── box.h
├── opengl/
│   └── visualize.c
├── README.md
```

---

## What I Learned

* 포인터와 배열의 차이점에 대한 명확한 이해
* 동적 메모리 할당 시 메모리 관리의 중요성
* 3차원 구조를 코드로 표현하는 방법
* 논리적 문제 해결 과정 설계 능력 향상

---

## Future Improvements

* 박스 회전(rotation)을 고려한 최적 포장 알고리즘
* 다양한 박스 개수로 확장
* OpenGL 기반 실시간 시각화 강화
* 구조체와 모듈 분리 개선

![Array_WDH](https://github.com/user-attachments/assets/cde672ac-324a-4bed-8b18-4d12e43d9e60)
![Choose_Width,depth,height](https://github.com/user-attachments/assets/9a926d52-3de1-487f-ba9d-4e8c8472b557)
![opengl](https://github.com/user-attachments/assets/2c08e206-c0bd-4925-8d78-1357d9100d94)

[![Video Label](http://img.youtube.com/vi/'cKpNziEF3Dw'/0.jpg)]

---

## Author

* **Taemin Kim**
* GitHub: [https://github.com/ktm0110](https://github.com/ktm0110)

---
