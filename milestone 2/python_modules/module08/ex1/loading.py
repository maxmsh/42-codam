import sys
import importlib
import importlib.metadata


REQUIRED = {
    "pandas": "Data manipulation ready",
    "numpy": "Numerical computation ready",
    "matplotlib": "Visualization ready",
}


def check_dependency(package: str) -> tuple[bool, str]:
    try:
        importlib.import_module(package)
        version = importlib.metadata.version(package)
        return True, version
    except ImportError:
        return False, ""
    except importlib.metadata.PackageNotFoundError:
        return True, "unknown"


def show_dependency_status() -> bool:
    print("Checking dependencies:")
    all_ok = True
    for package, description in REQUIRED.items():
        ok, version = check_dependency(package)
        if ok:
            print(f"[OK] {package} ({version}) - {description}")
        else:
            print(f"[MISSING] {package} - {description}")
            all_ok = False
    return all_ok


def show_missing_instructions() -> None:
    print()
    print("Missing dependencies detected!")
    print()
    print("Install with pip:")
    print("  pip install -r requirements.txt")
    print()
    print("Install with Poetry:")
    print("  poetry install")
    print("  poetry run python loading.py")
    print()
    print("pip vs Poetry:")
    print("  pip:    simple, installs globally or in active venv")
    print("  Poetry: manages its own venv + locks exact versions")


def run_analysis() -> None:
    import numpy as np  # noqa: PLC0415
    import pandas as pd  # noqa: PLC0415
    import matplotlib  # noqa: PLC0415
    matplotlib.use("Agg")
    import matplotlib.pyplot as plt  # noqa: PLC0415

    n_points = 1000
    print()
    print("Analyzing Matrix data...")
    print(f"Processing {n_points} data points...")

    rng = np.random.default_rng(42)
    timestamps = np.arange(n_points)
    signal = rng.normal(0, 1, n_points).cumsum()
    anomaly_mask = rng.random(n_points) < 0.02
    anomalies = np.where(
        anomaly_mask, signal + rng.normal(5, 1, n_points), np.nan
    )

    df = pd.DataFrame({
        "timestamp": timestamps,
        "signal": signal,
        "anomaly": anomalies,
    })

    mean_val = df["signal"].mean()
    std_val = df["signal"].std()

    print("Generating visualization...")

    fig, (ax1, ax2) = plt.subplots(2, 1, figsize=(12, 6))
    fig.suptitle("Matrix Data Analysis", fontsize=14, fontweight="bold")

    ax1.plot(df["timestamp"], df["signal"], color="green", linewidth=0.8,
             label="Matrix signal")
    ax1.scatter(df["timestamp"], df["anomaly"], color="red", s=20, zorder=5,
                label="Anomalies")
    ax1.axhline(mean_val, color="cyan", linestyle="--", linewidth=1,
                label=f"Mean: {mean_val:.2f}")
    ax1.set_xlabel("Timestamp")
    ax1.set_ylabel("Signal")
    ax1.set_title("Live Matrix Feed")
    ax1.legend(fontsize=8)
    ax1.set_facecolor("#0a0a0a")
    fig.patch.set_facecolor("#111111")
    ax1.tick_params(colors="white")
    ax1.xaxis.label.set_color("white")
    ax1.yaxis.label.set_color("white")
    ax1.title.set_color("white")

    ax2.hist(df["signal"], bins=40, color="green", alpha=0.7, edgecolor="lime")
    ax2.axvline(mean_val, color="cyan", linestyle="--",
                label=f"Mean: {mean_val:.2f}")
    ax2.axvline(mean_val + std_val, color="yellow", linestyle=":",
                label=f"+1σ: {mean_val + std_val:.2f}")
    ax2.axvline(mean_val - std_val, color="yellow", linestyle=":")
    ax2.set_xlabel("Value")
    ax2.set_ylabel("Frequency")
    ax2.set_title("Signal Distribution")
    ax2.legend(fontsize=8)
    ax2.set_facecolor("#0a0a0a")
    ax2.tick_params(colors="white")
    ax2.xaxis.label.set_color("white")
    ax2.yaxis.label.set_color("white")
    ax2.title.set_color("white")

    plt.tight_layout()
    output_file = "matrix_analysis.png"
    plt.savefig(output_file, dpi=100, bbox_inches="tight",
                facecolor=fig.get_facecolor())
    plt.close()

    print()
    print("Analysis complete!")
    print(f"Results saved to: {output_file}")


def main() -> None:
    print("LOADING STATUS: Loading programs...")
    print()

    all_ok = show_dependency_status()

    if not all_ok:
        show_missing_instructions()
        sys.exit(1)

    run_analysis()


if __name__ == "__main__":
    main()
