# Database

There is no database or persistent storage. Stack and tree state exists only in process memory and is released when the owning object is destroyed. Consumers requiring persistence must define serialization and recovery behavior separately.
