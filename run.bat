@echo off

echo "Y = 10"
make -s samples N_SAMPLES=10
for /l %%x in (1, 1, 30) do (
    echo RUN %%x
    make -s run_samples
    echo:
)
echo "Y = 100"
make -s samples N_SAMPLES=100
for /l %%x in (1, 1, 30) do (
    echo RUN %%x
    make -s run_samples
    echo:
)
echo "Y = 1000"
make -s samples N_SAMPLES=1000
for /l %%x in (1, 1, 30) do (
    echo RUN %%x
    make -s run_samples
    echo:
)
echo "Y = 10000"
make -s samples N_SAMPLES=10000
for /l %%x in (1, 1, 30) do (
    echo RUN %%x
    make -s run_samples
    echo:
)
echo "Y = 100000"
make -s samples N_SAMPLES=100000
for /l %%x in (1, 1, 30) do (
    echo RUN %%x
    make -s run_samples
    echo:
)
echo "Y = 1000000"
make -s samples N_SAMPLES=1000000
for /l %%x in (1, 1, 30) do (
    echo RUN %%x
    make -s run_samples
    echo:
)
echo "Y = 10000000"
make -s samples N_SAMPLES=10000000
for /l %%x in (1, 1, 30) do (
    echo RUN %%x
    make -s run_samples
    echo:
)
