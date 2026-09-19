# TC264 GPS / 视觉导航智能车

基于 **Infineon AURIX TC264D** 的多功能智能车：GPS 航点导航 + 摄像头视觉循迹 + IMU 航向保持 + 无刷电机驱动。
底层使用逐飞科技（SEEKFREE）开源库，业务代码集中在 `code/` 与 `user/`。

> 对应简历项目：全国大学生智能汽车竞赛 — AURIX TC264D 导航小车（软件核心）

## 功能亮点

- **GPS 航点导航**：3 条路径 × 最多 16 航点，Flash 掉电保存；距离/方位角解算 + PID 舵机转向
- **摄像头循迹**：MT9V03x 灰度图，OTSU 自适应二值化 → 中线提取 → PID 转向
- **IMU 航向辅助**：IMU963RA 20ms 采样，GPS 信号弱时切换惯性导航保持方向
- **多级菜单调参**：IPS200 状态机菜单，运行时改 PID / 舵机 / 电机 / 航点
- **轻量数学库 `GL_Math`**：sin/cos/atan2/sqrt、低通滤波，降低对标准库体积依赖
- **双核 + 定时中断调度**：CCU60/CCU61 分频处理 IMU、按键、导航计算

## 硬件平台

| 组件 | 型号 / 说明 |
|------|-------------|
| 主控 | Infineon TC264D（AURIX TriCore 双核） |
| 开发板 | 逐飞 SEEKFREE TC264 通用主板 |
| 驱动 | TC264-GTM 无刷驱动板（自制 PCB） |
| 摄像头 | MT9V03x 灰度 |
| IMU | IMU963RA（9 轴） |
| GPS | GNSS 模块（UART3） |
| 显示 | IPS200 TFT（SPI） |
| 电机/舵机 | BLDC（GTM）/ PWM 舵机 50Hz |

## 仓库结构

```
TC264-GPS-Vision-Car/
├── README.md
├── docs/
│   └── project-intro-zh.md      # 详细项目介绍
├── pcb/                          # 自制 PCB 工程（若有）
└── ALL_THE_LAST_2025_7/          # ADS 工程根目录
    ├── user/                     # cpu0_main / cpu1_main / isr
    ├── code/                     # 业务模块（核心）
    │   ├── GPS.c/h               # 航点解析、Flash、导航
    │   ├── Menu.c/h              # 多级菜单
    │   ├── Image.c/h             # OTSU + 中线 + 转向
    │   ├── Agorithm.c/h          # 位置式/增量式 PID
    │   ├── GL_Math.c/h           # 轻量数学库
    │   ├── IMU_1.c/h
    │   ├── BD_ctrl.c/h
    │   └── Common_Peripherals.c/h
    ├── libraries/                # 逐飞开源库 + iLLD
    └── *.lsl / *.project         # ADS 工程配置
```

## 开发环境

- **IDE**：AURIX Development Studio (ADS)
- **编译器**：Tasking C/C++
- **开源库**：逐飞 SEEKFREE zf_common / zf_driver / zf_device / zf_components（GPL-3.0）

导入方式：ADS → File → Import → Existing Projects → 选择 `ALL_THE_LAST_2025_7`。

## 中断调度（摘要）

| 中断 | 周期 | 任务 |
|------|------|------|
| CCU60_CH0 | 20ms | IMU 采集与姿态 |
| CCU60_CH1 | 5ms | 按键扫描 |
| CCU61_CH0 | 5ms | GPS / 惯性导航计算 |
| UART3_RX | 回调 | GNSS 数据接收 |

## 技术栈

`AURIX TC264D` · `C` · `SEEKFREE` · `PID` · `GPS/GNSS` · `IMU` · `MT9V03x` · `OTSU` · `Flash` · `双核调度`

## 说明

- 本仓库整理竞赛工程，去除 ADS `.metadata` 与 `Debug` 编译产物，便于阅读。
- 更完整的设计说明、踩坑记录见 `docs/project-intro-zh.md`。
- 基于逐飞开源库二次开发，请遵循其 **GPL-3.0** 协议。

## 作者

shuifanyu / 软件核心 · GitHub 
