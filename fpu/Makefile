# ==========================================
# Verilator Makefile for FPU testbenches
# ==========================================

# Verilatorコマンドと共通フラグ
VERILATOR = verilator
# -Wall: 警告を有効化
# -Wno-fatal: 警告が発生してもエラー終了せずビルドを続行する
# --cc: C++コードを出力
# --exe: 実行ファイルをビルド
# --build: 生成されたMakefileを自動で叩いてビルドまで行う
# -j 0: 並列ビルド
VFLAGS = -Wall -Wno-fatal --cc --exe --build -j 0

# C++のマルチスレッドを利用するためのフラグ (itof等で使用)
THREAD_FLAGS = -CFLAGS "-std=c++14 -pthread" -LDFLAGS "-pthread"

.PHONY: all fadd fdiv fmul fsqrt itof ftoi clean

# デフォルトターゲット
all: fadd fdiv fmul fsqrt itof

# ------------------------------------------
# 1. fadd (test_fadd.cpp)
# ------------------------------------------
fadd:
	@echo "Building fadd..."
	$(VERILATOR) $(VFLAGS) fadd.sv test_fadd.cpp \
		--top-module fadd --prefix Vfadd -o test_fadd
	@echo "Running test_fadd..."
	./obj_dir/test_fadd

# ------------------------------------------
# 2. fdiv_10 (tb_fdiv_10.cpp)
# サブモジュールとして fdiv_mantissa_10.sv を使用
# ------------------------------------------
fdiv:
	@echo "Building fdiv_10..."
	$(VERILATOR) $(VFLAGS) fdiv_10.sv fdiv_mantissa_10.sv tb_fdiv_10.cpp \
		--top-module fdiv --prefix Vfdiv -o tb_fdiv_10
	@echo "Running tb_fdiv_10..."
	./obj_dir/tb_fdiv_10

# ------------------------------------------
# 3. fmul (tb_fmul.cpp)
# ------------------------------------------
fmul:
	@echo "Building fmul..."
	$(VERILATOR) $(VFLAGS) fmul.sv tb_fmul.cpp \
		--top-module fmul --prefix Vfmul -o tb_fmul
	@echo "Running tb_fmul..."
	./obj_dir/tb_fmul

# ------------------------------------------
# 4. fsqrt_10 (test_sqrt.cpp)
# ------------------------------------------
fsqrt_10:
	@echo "Building fsqrt_10..."
	$(VERILATOR) $(VFLAGS) fsqrt_10.sv test_sqrt.cpp \
		--top-module fsqrt --prefix Vfsqrt_10 -o test_sqrt
	@echo "Running test_sqrt..."
	./obj_dir/test_sqrt

fsqrt_3:
	@echo "Building fsqrt_3..."
	$(VERILATOR) $(VFLAGS) fsqrt_3.sv test_sqrt_3.cpp \
		--top-module fsqrt --prefix Vfsqrt_3 -o test_sqrt
	@echo "Running test_sqrt..."
	./obj_dir/test_sqrt
# ------------------------------------------
# 5. itof (test_itof.cpp)
# ------------------------------------------
itof:
	@echo "Building itof..."
	$(VERILATOR) $(VFLAGS) $(THREAD_FLAGS) itof_without_fadd.sv test_itof.cpp \
		--top-module itof --prefix Vitof -o test_itof
	@echo "Running test_itof..."
	./obj_dir/test_itof

# ------------------------------------------
# 6. ftoi (test_ftoi.cpp)
# ------------------------------------------
ftoi:
	@echo "Building ftoi (using itof module internally)..."
	$(VERILATOR) $(VFLAGS) $(THREAD_FLAGS) itof_without_fadd.sv test_ftoi.cpp \
		--top-module itof --prefix Vitof -o test_ftoi
	@echo "Running test_ftoi..."
	./obj_dir/test_ftoi

# ------------------------------------------
# Clean
# ------------------------------------------
clean:
	@echo "Cleaning up..."
	rm -rf obj_dir
