#pragma once
DWORD64 automatic[]
{
	1545779598, // AK - 47;
	-1758372725, // Tommy
	1796682209, // SMG
	-1812555177,// LR - 300
	1318558775, // MP5
	-2069578888, // M249
};

DWORD64 sniper[]
{
	-778367295, // L96
	1588298435, // Bolty
};

DWORD64 shotguns[]
{
	795371088, // Pump Shotty
	-41440462, // Spas-12 Shotty
	-765183617, // Double Barrel Shotty
	-1367281941, // Waterpipe Shotty
};

DWORD64 semiautomatic[]{
	-904863145, // Semi Auto Rifle 
	818877484, // Semi Pistol
	-852563019, // M92 Pistol
	1373971859, // Python
	649912614, // Revolver
	28201841, // M39 Rifle
	1953903201, // NailGun
	-1123473824, // Grenade Launcher
	1103488722, // Snowball Gun
};

DWORD64 eoka[]
{
	-75944661, // Eoka;
};
DWORD64 bow[]
{
	1443579727, // Bow
};

DWORD64 compound_bow[]
{
	884424049, // Compound Bow
};

DWORD64 crossbow[]
{
	1965232394, // Cross Bow
};



DWORD64 meele[]
{
	1711033574, // Bone Club
	1814288539, // Bone Knife
	-194509282, // Butcher Knife
	1789825282, // Candy Cane Club
	2040726127, // Combat Knife
	1540934679, // Wooden Spear
	-262590403, // Salvaged Axe
	-1506397857, //Salvaged Hammer
	-1780802565, // Salvaged Icepick
	-1583967946, // Stone Hatchet
	171931394, // Stone Pickaxe
	1326180354, // Salvaged Sword
	1602646136, // Stone Spear
	200773292, // Hammer
	-1252059217, // Hatchet
	1488979457, // Jackhammer
	-1302129395, // Pickaxe
	-1978999529, // Salvaged Cleaver
	1090916276, // Pitchfork
	1491189398, // Paddle
	-1137865085, // Machete
	-1966748496, // Mace
	-1469578201, // Long Sword
	795236088, // Torch
	963906841, // Rock
};


#define oGameObjectManager 0x17D69F8
#define oBaseNetworkable   0x31C0798 //"Name": "Class$BaseNetworkable","Signature" : "BaseNetworkable_c*"

//class Client
#define oClient 0x31C05C8 //"Name": "Class$ConVar.Client", "Signature" : "ConVar_Client_c*"
#define oCamspeed 0x2C //public static float camspeed;
#define oCamlerp 0x20 //public static float camlerp;



//class Graphics
#define oCustomFOV 0x31BF4D8 //"Name": "ConVar.Graphics_TypeInfo",  //"Signature": "ConVar_Graphics_c*"


// Class Climate
#define oNoRain 0x31BC988  //SingletonComponent_Climate__c*


//class BasePlayer
#define oBasePlayerAimbot 0x31C0BD8 // BasePlayer_c* decimal to hex in script.json
#define oPlayerFlags 0x638 // public BasePlayer.PlayerFlags playerFlags;
#define oPlayerName 0x698 // protected string _displayName;
#define oPlayerHealth 0x214 // private float _health;
#define olastSentTickTime 0x60C // не требо private float lastSentTickTime;
#define oClientTeam 0x580 // public PlayerTeam clientTeam;
#define oLifestate 0x20C // public BaseCombatEntity.LifeState lifestate;
#define oSteamID 0x680 // public ulong userID;
#define oPlayerInventory 0x648 // public PlayerInventory inventory;
#define oActiveUID 0x5B0// private uint clActiveItem;
#define oFrozen 0x4B0// public bool Frozen;
#define oWaterBonus 0x700// public float clothingWaterSpeedBonus;
#define oNoBlockAiming 0x6F8 // public bool clothingBlocksAiming;
#define oSpeedReduction 0x6FC// public float clothingMoveSpeedReduction;
#define oClientTickInterval 0x608  // public float clientTickInterval;
#define oClothingAccuracyBonus 0x704 //	public float clothingAccuracyBonus;
#define oAttachmentBoneCache 0x278 //private Transform attachmentBoneCache; // 0x270
#define oSilentWalk 0x5C8 //public ModelState modelState;
#define oNewVelocity 0x1FC //private Vector3 newVelocity
#define oBoneTransforms 0x48 //public Transform[] boneTransforms; // 0x48
#define oModel 0x120 //public Model model;_public class BaseEntity : BaseNetworkable, IProvider, ILerpTarget, IPrefabPreProcess // TypeDefIndex: 8714
#define oHornOrigin 0x1D0 // public GameObject hornOrigin;

//EntityRef
#define oHeld 0x98 //private EntityRef heldEntity
#define oStancePenalty 0x30C //private float stancePenalty;
#define	oAimconePenalty	0x310 //private float aimconePenalty;
#define	oHipAimCone 0x2DC //public float hipAimCone;
#define	oAimCone 0x2D8 //public float aimCone;			(class BaseProjectile)
#define	oAimconePenaltyPerShot 0x2E0 //public float aimconePenaltyPerShot;
#define oSuccessFraction 0x350  //public float successFraction; // protected bool attackReady;
#define oAttackRadius 0x284 //public float attackRadius;
#define oEffectiveRange 0x1EC //public float effectiveRange;
#define oIsAutomatic 0x288 //public bool isAutomatic;
#define oMaxDistance 0x280 //public float maxDistance;			(class BaseMelee)
#define oRepeatDelay 0x1E4 //public float repeatDelay;
#define oBlockSprintOnAttack 0x289 //public bool blockSprintOnAttack;
#define oRapidFire 0x1E4 //public float repeatDelay;
#define oSuperBowArrowBack 0x354 //private float arrowBack;
#define oCompoundInstant 0x368 //public float stringHoldDurationMax;


//BaseProjectile
#define oAuto 0x278 //public bool automatic;
#define oFastReload 0x2B0 // bool fractionalReload
#define oDistance 0x278 //private Transform attachmentBoneCache; public float maxDistance; // 0x278
#define oprojectileVelocityScale 0x274 //public float projectileVelocityScale
#define oThickBullet 0x2C //public float thickness; // 0x2C
#define oListProjectiles 0x348 //private List<Projectile> createdProjectiles; // 0x348



//BaseMovement
#define oPlayerMovement 0x4D8 // public BaseMovement movement;
#define oGravityMultiplier 0x74 // public float gravityMultiplier;
#define oGroundAngleNew 0xB8 // private float groundAngleNew;


//RecoilProperties
#define oRecoilProperties 0x2C8 //public RecoilProperties recoil;
#define oRecoilMinYaw 0x18 //public float recoilYawMin;
#define oRecoilMaxYaw 0x1C //public float recoilYawMax;
#define oRecoilMinPitch 0x20 //public float recoilPitchMin;
#define oRecoilMaxPitch 0x24 //public float recoilPitchMax;


//PlayerModel
#define oPlayerModel 0x4A8 // public PlayerModel playerModel;
#define oVisible 0x248 // internal bool visible;


//PlayerInput
#define oPlayerInput 0x4D0// public PlayerInput input;
#define oBodyAngles 0x3C // private Vector3 bodyAngles;
#define oRecoilAngles 0x64 // public Vector3 recoilAngles;
#define oHasKeyFocus 0x94 // private bool hasKeyFocus;


#define oArrowBack 0x354 // private float arrowBack;
#define oTriggerReady 0x350 // protected bool attackReady;
#define oItemDefinition 0x20 // public ItemDefinition info;
#define oItemid 0x18 // public int itemid;


#define oNetworkable 0x50// public Networkable net;
#define oNetworkId 0x10//public uint ID;
#define oCanAttack 0x28CE70// public bool CanAttack()
#define oSetFlying 0x1D0D360 //public void set_flying(bool value) { } 
#define oSendProjectileAttack 0x3182C0 //     public void SendProjectileAttack(PlayerProjectileAttack attack) { }
#define oHitID 0x2C// public uint hitID;
#define oHitPartID 0x64// public uint hitPartID;
#define oHitBone 0x30// public uint hitBone;  ?
#define oHitMaterialID 0x68 // public uint hitMaterialID;
#define oPlayerAttack 0x18 // public PlayerAttack playerAttack;
#define oAttack 0x18 // public Attack attack;
#define oHitNormalWorld 0x4C // public Vector3 hitNormalWorld; ?
#define oCanAttack 0x28CE70 // public bool CanAttack()
#define oCreateProjectile 0x27E8A0 // private Projectile CreateProjectile(string prefabPath, Vector3 pos, Vector3 forward, Vector3 velocity) { }
#define oBlockSprint 0x2FEA50 // public virtual void BlockSprint(float duration = 0,2) { }
#define oGetSpeed 0x296940 //     public float GetSpeed(float running, float ducking) { }
#define oGetIndexedSpreadScalar 0x54DEC0 // public float GetIndexedSpreadScalar(int shotIndex, int maxShots) { }