# a_curtain include WIKI

-------------------------------------------------

**ShowPlayerCurtain:**
-----------------------------------

**Parameters:**
```
(
  playerid, // player id
  time, // time to open and close (ex.: time = 5000 | 2500 to open & 2500 to close)
  curtainid, // id curtain, as if it were "dialogid"
  permanence // How long will the curtain be closed
);
```

**Return Values:**
  - 1: The function executed successfully.
  - 0: The function failed to execute. The player is not connected, or a curtain already exists (IsCurtainExist).

**Example Usage:**
```
enum {
  CURTAIN_EX
};

public OnPlayerConnect (playerid) {
  ShowPlayerCurtain (playerid, ((1000 * 2) * 2), CURTAIN_EX, (1000 * 2));
  return
    1
  ;
}
```

-----------------------------------

**IsCurtainExist:**
-----------------------------------

**Parameters:**
```
(
  playerid, // player id
);
```

**Return Values:**
  - 1: Curtain exists.
  - 0: Curtain does not exist, The player is not connected, or the textdraw has already been created.

**Example Usage:**
```
enum {
  CURTAIN_EX
};

public OnPlayerConnect (playerid) {
  if (!IsCurtainExist (playerid))
    ShowPlayerCurtain (playerid, ((1000 * 2) * 2), CURTAIN_EX, (1000 * 2));
  return
    1
  ;
}
```
-------------------------------------------------

**OnPlayerUpdateCurtain:**
-----------------------------------

**Parameters:**
```
(
  playerid, // player id
  time, // time to open and close (ex.: time = 5000 | 2500 to open & 2500 to close)
  permanence, // How long will the curtain be closed
  curtainid, // id curtain, as if it were "dialogid"
  bool: invert, // controls "progress" (progress -- | progress ++)
  progress // progress of closing or opening
)
```

**Return Values:**
  - 1: The function executed successfully.

**Example Usage:**
```
public OnPlayerUpdateCurtain (playerid, time, permanence, curtainid, bool: invert, progress) {
  switch (progress) {
    case 125: { // {0, .., 255}
      SendCientMessage (playerid, -1, "125");
    }
  }
  return
    1
  ;
}
```

-----------------------------------

**OnPlayerCurtainClosed:**
-----------------------------------

**Parameters:**
```
(
  playerid, // player id
  curtainid, // id curtain, as if it were "dialogid"
)
```

**Return Values:**
  - 1: The function executed successfully.

**Example Usage:**
```
enum {
  CURTAIN_EX
};

public OnPlayerConnect (playerid) {
  ShowPlayerCurtain (playerid, ((1000 * 2) * 2), CURTAIN_EX, (1000 * 2));
  return
    1
  ;
}

public OnPlayerCurtainClosed (playerid, curtainid) {
  switch (curtainid) {
    case CURTAIN_EX: {
      SendCientMessage (playerid, -1, "Execute CURTAIN_EX");
    }
  }
  return
    1
  ;
}
```

-------------------------------------------------
