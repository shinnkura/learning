### ■ 建物・敷地の基本情報

**MSSubClass（建物の種類）**  
住宅の構造・階数・築年による分類（例：1階建て、2階建て、PUDなど）

| コード | 説明 |
|-------|------|
| 20    | 1階建て（1946年以降） |
| 30    | 1階建て（1945年以前） |
| 40    | 1階建て＋屋根裏部屋（全年代） |
| 45    | 1.5階建て（屋根裏未完成） |
| 50    | 1.5階建て（屋根裏完成済） |
| 60    | 2階建て（1946年以降） |
| 70    | 2階建て（1945年以前） |
| 75    | 2.5階建て |
| 80    | スプリット/多層階 |
| 85    | スプリット・フォイヤー |
| 90    | 二世帯住宅（デュプレックス） |
| 120〜190 | PUD（計画的住宅開発）タイプ |

**MSZoning（用途地域）**  
物件の一般的な用途分類（例：商業地域、住宅地など）

| コード | 説明 |
|-------|------|
| A     | 農業地域 |
| C     | 商業地域 |
| FV    | 浮動住宅地（Floating Village） |
| I     | 工業地域 |
| RH〜RM | 高・中・低密度住宅地、住宅公園など |

**LotFrontage**：接道長さ（フィート）  
**LotArea**：敷地面積（平方フィート）  
**Street**：接道タイプ（Gravel＝砂利／Paved＝舗装）  
**Alley**：路地へのアクセスの有無  
**LotShape**：敷地形状（正方形／やや不規則など）  
**LandContour**：土地の高低（平坦／丘／傾斜）  
**Utilities**：公共設備の整備状況（上下水・電気・ガスの有無）  
**LotConfig**：敷地配置（角地／袋小路／複数面接道など）  
**LandSlope**：傾斜の程度（緩やか／中程度／急斜面）

---

### ■ 周辺環境・ロケーション

**Neighborhood**：市内の地区名（Ames市内の地名）  
**Condition1 / Condition2**：周辺の特徴（幹線道路、鉄道、緑地隣接など）

---

### ■ 建物の構造・スタイル

**BldgType**：建物の形態（一戸建て、タウンハウス等）  
**HouseStyle**：階層構成（平屋、2階建て、スプリットなど）  
**YearBuilt**：建築年  
**YearRemodAdd**：リフォーム年  
**RoofStyle / RoofMatl**：屋根の形状・素材  
**Exterior1st / Exterior2nd**：外装材（主材、副材）  
**MasVnrType / MasVnrArea**：外壁のレンガ・石材タイプと面積  
**ExterQual / ExterCond**：外装の質と状態（Ex: 優秀〜Po: 劣悪）  
**Foundation**：基礎の種類（コンクリート、石、木など）

---

### ■ 地下（Basement）

**BsmtQual / BsmtCond**：地下の天井高と状態  
**BsmtExposure**：地下の外への開放度（ウォークアウトなど）  
**BsmtFinType1/2**：地下の居住区分（居住用／リクリエーション／未完成など）  
**BsmtFinSF1/2 / BsmtUnfSF / TotalBsmtSF**：地下の各エリアの面積

---

### ■ 設備・機能

**Heating / HeatingQC**：暖房タイプと品質  
**CentralAir**：中央空調の有無  
**Electrical**：電気設備の種類（ブレーカー、ヒューズなど）

---

### ■ 面積

**1stFlrSF / 2ndFlrSF**：1階／2階の床面積  
**LowQualFinSF**：低品質な居住面積  
**GrLivArea**：地上階の合計居住面積

---

### ■ バス・ベッドルーム

**BsmtFullBath / BsmtHalfBath**：地下のバスルーム数  
**FullBath / HalfBath**：地上階のバスルーム数  
**Bedroom**：ベッドルーム数（地下を除く）  
**Kitchen / KitchenQual**：キッチン数と品質  

---

### ■ その他の内部情報

**TotRmsAbvGrd**：地上階の部屋数（バスルーム除く）  
**Functional**：住宅の機能性評価（Typ：問題なし、Sev：重度損傷）  
**Fireplaces / FireplaceQu**：暖炉の数と品質  

---

### ■ ガレージ

**GarageType**：ガレージの配置（家と一体化、別棟など）  
**GarageYrBlt**：ガレージ建築年  
**GarageFinish**：内装仕上げ（未仕上／簡易仕上げなど）  
**GarageCars / GarageArea**：駐車台数、面積  
**GarageQual / GarageCond**：品質と状態  

---

### ■ 外構

**PavedDrive**：舗装状況（完全／部分／未舗装）  
**WoodDeckSF / OpenPorchSF / EnclosedPorch / 3SsnPorch / ScreenPorch**：各種ポーチやデッキの面積  
**PoolArea / PoolQC**：プール面積と品質  
**Fence**：フェンスの有無と質  
**MiscFeature / MiscVal**：その他の設備（倉庫、エレベータなど）とその評価額  

---

### ■ 取引情報

**MoSold / YrSold**：売却月／年  
**SaleType**：販売形態（通常、新築、裁判所売却など）  
**SaleCondition**：売却状況（通常／家族間取引／未完成など）

---