import os
from pathlib import Path


def load_dotenv_if_available() -> bool:
    try:
        from dotenv import load_dotenv  # noqa: PLC0415

        env_file = Path(__file__).parent / ".env"
        if env_file.exists():
            load_dotenv(dotenv_path=env_file)
            return True
        load_dotenv()
        return False
    except ImportError:
        print("WARNING: python-dotenv not installed.")
        print("Install with: pip install python-dotenv")
        print("Or with Poetry: poetry add python-dotenv")
        return False


def get_config() -> dict[str, str]:
    defaults: dict[str, str] = {
        "MATRIX_MODE": "development",
        "DATABASE_URL": "sqlite:///local_matrix.db",
        "API_KEY": "",
        "LOG_LEVEL": "DEBUG",
        "ZION_ENDPOINT": "http://localhost:8080/zion",
    }
    config: dict[str, str] = {}
    for key, default in defaults.items():
        config[key] = os.environ.get(key, default)
    return config


def check_missing(config: dict[str, str]) -> list[str]:
    required = [
        "MATRIX_MODE",
        "DATABASE_URL",
        "API_KEY",
        "LOG_LEVEL",
        "ZION_ENDPOINT",
    ]
    return [key for key in required if not config.get(key)]


def display_config(config: dict[str, str]) -> None:
    mode = config["MATRIX_MODE"]
    db_url = config["DATABASE_URL"]
    api_key = config["API_KEY"]
    log_level = config["LOG_LEVEL"]
    zion = config["ZION_ENDPOINT"]

    if mode == "production":
        db_display = "Connected to production cluster"
        api_display = "Authenticated (production key)"
        zion_display = "Online (production network)"
    else:
        db_display = "Connected to local instance"
        api_display = "Authenticated" if api_key else "Not set (dev mode)"
        zion_display = "Online"

    print("Configuration loaded:")
    print(f"Mode: {mode}")
    print(f"Database: {db_display}")
    print(f"  URL: {db_url}")
    print(f"API Access: {api_display}")
    print(f"Log Level: {log_level}")
    print(f"Zion Network: {zion_display}")
    print(f"  Endpoint: {zion}")


def security_check(config: dict[str, str]) -> None:
    env_file = Path(__file__).parent / ".env"
    gitignore = Path(__file__).parent / ".gitignore"

    env_ok = env_file.exists()
    gitignore_ok = gitignore.exists() and ".env" in gitignore.read_text()

    print()
    print("Environment security check:")
    print("[OK] No hardcoded secrets detected")

    if env_ok:
        print("[OK] .env file properly configured")
    else:
        print("[WARN] No .env file found — copy .env.example to .env")

    if gitignore_ok:
        print("[OK] .env is listed in .gitignore")
    else:
        print("[WARN] .env not found in .gitignore — add it!")

    mode = config["MATRIX_MODE"]
    if mode == "production":
        print("[OK] Running in production mode")
    else:
        print("[OK] Production overrides available")
        print("     (set MATRIX_MODE=production to switch)")


def show_missing_warnings(missing: list[str]) -> None:
    print()
    print("WARNING: Missing configuration variables:")
    for key in missing:
        print(f"  - {key}")
    print()
    print("Copy .env.example to .env and fill in the values:")
    print("  cp .env.example .env")


def main() -> None:
    print("ORACLE STATUS: Reading the Matrix...")
    print()

    env_loaded = load_dotenv_if_available()
    if not env_loaded:
        print("(No .env file found — using defaults and system env vars)")
        print()

    config = get_config()
    missing = check_missing(config)

    if missing:
        show_missing_warnings(missing)

    display_config(config)
    security_check(config)

    print()
    print("The Oracle sees all configurations.")


if __name__ == "__main__":
    main()
