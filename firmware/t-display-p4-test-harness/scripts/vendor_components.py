Import("env")

from pathlib import Path
import subprocess

project_dir = Path(env.subst("$PROJECT_DIR"))
vendor_dir = project_dir / ".pio" / "vendor" / "T-Display-P4"

if not (vendor_dir / ".git").exists():
    vendor_dir.parent.mkdir(parents=True, exist_ok=True)
    subprocess.check_call([
        "git", "clone", "--depth", "1", "--recursive",
        "https://github.com/Xinyuan-LilyGO/T-Display-P4.git",
        str(vendor_dir),
    ])

