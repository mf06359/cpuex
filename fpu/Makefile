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
VFLAGS = -Wall --cc --exe --build -j 0 # -Wno-fatal 

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
fdiv_10:
	@echo "Building fdiv_10..."
	$(VERILATOR) $(VFLAGS) fdiv_10.sv fdiv_mantissa_10.sv tb_fdiv_10.cpp \
		--top-module fdiv --prefix Vfdiv -o tb_fdiv_10
	@echo "Running tb_fdiv_10..."
	./obj_dir/tb_fdiv_10

fdiv:
	@echo "Building fdiv..."
	$(VERILATOR) $(VFLAGS) fdiv.sv test_fdiv.cpp \
		--top-module fdiv --prefix Vfdiv -o test_fdiv
	@echo "Running test_fdiv..."
	./obj_dir/test_fdiv
# ------------------------------------------
# 3. fmul (tb_fmul.cpp)
# ------------------------------------------
fmul:
	@echo "Building fmul..."
	$(VERILATOR) $(VFLAGS) fmul.sv test_fmul.cpp \
		--top-module fmul --prefix Vfmul -o test_fmul
	@echo "Running test_fmul..."
	./obj_dir/test_fmul

# ------------------------------------------
# 4. fsqrt_10 (test_sqrt.cpp)
# ------------------------------------------
fsqrt_10:
	@echo "Building fsqrt_10..."
	$(VERILATOR) $(VFLAGS) fsqrt_10.sv test_sqrt.cpp \
		--top-module fsqrt --prefix Vfsqrt_10 -o test_sqrt
	@echo "Running test_sqrt..."
	./obj_dir/test_sqrt

fsqrt:
	@echo "Building fsqrt_3..."
	$(VERILATOR) $(VFLAGS) fsqrt.sv test_sqrt.cpp \
		--top-module fsqrt --prefix Vfsqrt -o test_sqrt
	@echo "Running test_sqrt..."
	./obj_dir/test_sqrt
# ------------------------------------------
# 5. itof (test_itof.cpp)
# ------------------------------------------
itof:
	@echo "Building itof..."
	$(VERILATOR) $(VFLAGS) $(THREAD_FLAGS) itof.sv test_itof.cpp \
		--top-module itof --prefix Vitof -o test_itof
	@echo "Running test_itof..."
	./obj_dir/test_itof

# ------------------------------------------
# 6. ftoi (test_ftoi.cpp)
# ------------------------------------------
ftoi:
	@echo "Building ftoi (using ftoi module internally)..."
	$(VERILATOR) $(VFLAGS) $(THREAD_FLAGS) ftoi.sv test_ftoi.cpp \
		--top-module ftoi --prefix Vftoi -o test_ftoi
	@echo "Running test_ftoi..."
	./obj_dir/test_ftoi

# ------------------------------------------
# Clean
# ------------------------------------------
clean:
	@echo "Cleaning up..."
	rm -rf obj_dir
