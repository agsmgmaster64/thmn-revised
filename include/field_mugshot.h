#ifndef GUARD_FIELD_MUGSHOTS_H
#define GUARD_FIELD_MUGSHOTS_H

void CreateFieldMugshot(u32 id, u32 emote);
void CreateFieldMugshotAt(u32 id, u32 emote, u32 mugshot_x, u32 mugshot_y);
void RemoveFieldMugshot(void);
u8 GetFieldMugshotSpriteId(void);
u8 IsFieldMugshotActive(void);
void SetFieldMugshotSpriteId(u32 value);

#endif // GUARD_FIELD_MUGSHOTS_H
