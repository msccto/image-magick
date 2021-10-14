{
  Copyright 1999-2005 ImageMagick Studio LLC, a non-profit organization
  dedicated to making software imaging solutions freely available.
  
  You may not use this file except in compliance with the License.
  obtain a copy of the License at
  
    http://www.imagemagick.org/script/license.php
  
  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  ImageMagick structure members.

  NOTE: This is a simplifyed version of magick/magick-type.h
}

const MaxTextExtent = 4096;

const
  MagickFalse = 0;
  MagickTrue = 1;

type
  MagickBooleanType = cardinal;

  PMagickBooleanType = ^MagickBooleanType;

//#include "magick/semaphore.h"

{
  The Quantum Depth was fixed at 16 to make the code simpler

  In the future there is the possibility to go to the c bindings
 and implement the variable QuantumDepth here
}
const
  QuantumDepth = 16;

{$define QuantumLeap}

const
  MagickEpsilon = 1.0E-10;
  MaxColormapSize = 65536;
  MaxMap = 65535;
  QuantumFormat = '%u';
  QuantumRange = 65535;

type
  MagickRealType = double;
  Quantum = Word;

{
  Type declarations.
}
type
  MagickStatusType = Word;
  MagickOffsetType = Int64;
  MagickSizeType = Int64;

type
 ChannelType = (
  UndefinedChannel,
  RedChannel = $0001,
  GrayChannel = $0001,
  CyanChannel = $0001,
  GreenChannel = $0002,
  MagentaChannel = $0002,
  BlueChannel = $0004,
  YellowChannel = $0004,
  AlphaChannel = $0008,
  OpacityChannel = $0008,
  MatteChannel = $0008,     // deprecated */
  BlackChannel = $0020,
  IndexChannel = $0020,
  CompositeChannels = $002F,
  AllChannels = $7ffffff,
  TrueAlphaChannel = $0040, // extract actual alpha channel from opacity */
  RGBChannels = $0080,      // set alpha from  grayscale mask in RGB */
  GrayChannels = $0080,
  SyncChannels = $0100,     // channels should be modified equally */
  DefaultChannels = $7fffff7 // ((AllChannels | SyncChannels) &~ OpacityChannel)
  );


type
//  ChannelType = Byte;

  PChannelType = ^ChannelType;

type
 ClassType = (
  UndefinedClass,
  DirectClass,
  PseudoClass
 );

  PClassType = ^ClassType;

type
 ColorspaceType = (
  UndefinedColorspace,
  RGBColorspace,            // Linear RGB colorspace */
  GRAYColorspace,           // greyscale (non-linear) image (faked 1 channel) */
  TransparentColorspace,
  OHTAColorspace,
  LabColorspace,
  XYZColorspace,
  YCbCrColorspace,
  YCCColorspace,
  YIQColorspace,
  YPbPrColorspace,
  YUVColorspace,
  CMYKColorspace,           // negated linear RGB with black separated */
  sRGBColorspace,           // Default: non-linear sRGB colorspace */
  HSBColorspace,
  HSLColorspace,
  HWBColorspace,
  Rec601LumaColorspace,
  Rec601YCbCrColorspace,
  Rec709LumaColorspace,
  Rec709YCbCrColorspace,
  LogColorspace,
  CMYColorspace,            // negated linear RGB colorspace */
  LuvColorspace,
  HCLColorspace,
  LCHColorspace,            // alias for LCHuv */
  LMSColorspace,
  LCHabColorspace,          // Cylindrical (Polar) Lab */
  LCHuvColorspace,          // Cylindrical (Polar) Luv */
  scRGBColorspace,
  HSIColorspace,
  HSVColorspace,            // alias for HSB */
  HCLpColorspace,
  YDbDrColorspace,
  xyYColorspace,
  LinearGRAYColorspace      // greyscale (linear) image (faked 1 channel) */
 );

  PColorspaceType = ^ColorspaceType;

type
 CompositeOperator = (
  UndefinedCompositeOp,
  NoCompositeOp,
  ModulusAddCompositeOp,
  AtopCompositeOp,
  BlendCompositeOp,
  BumpmapCompositeOp,
  ChangeMaskCompositeOp,
  ClearCompositeOp,
  ColorBurnCompositeOp,
  ColorDodgeCompositeOp,
  ColorizeCompositeOp,
  CopyBlackCompositeOp,
  CopyBlueCompositeOp,
  CopyCompositeOp,
  CopyCyanCompositeOp,
  CopyGreenCompositeOp,
  CopyMagentaCompositeOp,
  CopyOpacityCompositeOp,
  CopyRedCompositeOp,
  CopyYellowCompositeOp,
  DarkenCompositeOp,
  DstAtopCompositeOp,
  DstCompositeOp,
  DstInCompositeOp,
  DstOutCompositeOp,
  DstOverCompositeOp,
  DifferenceCompositeOp,
  DisplaceCompositeOp,
  DissolveCompositeOp,
  ExclusionCompositeOp,
  HardLightCompositeOp,
  HueCompositeOp,
  InCompositeOp,
  LightenCompositeOp,
  LinearLightCompositeOp,
  LuminizeCompositeOp,
  MinusDstCompositeOp,
  ModulateCompositeOp,
  MultiplyCompositeOp,
  OutCompositeOp,
  OverCompositeOp,
  OverlayCompositeOp,
  PlusCompositeOp,
  ReplaceCompositeOp,
  SaturateCompositeOp,
  ScreenCompositeOp,
  SoftLightCompositeOp,
  SrcAtopCompositeOp,
  SrcCompositeOp,
  SrcInCompositeOp,
  SrcOutCompositeOp,
  SrcOverCompositeOp,
  ModulusSubtractCompositeOp,
  ThresholdCompositeOp,
  XorCompositeOp,
  // These are new operators, added after the above was last sorted.
  // The list should be re-sorted only when a new library version is
  // created.
  DivideDstCompositeOp,
  DistortCompositeOp,
  BlurCompositeOp,
  PegtopLightCompositeOp,
  VividLightCompositeOp,
  PinLightCompositeOp,
  LinearDodgeCompositeOp,
  LinearBurnCompositeOp,
  MathematicsCompositeOp,
  DivideSrcCompositeOp,
  MinusSrcCompositeOp,
  DarkenIntensityCompositeOp,
  LightenIntensityCompositeOp,
  HardMixCompositeOp,
  StereoCompositeOp
 );

  PCompositeOperator = ^CompositeOperator;

type
  // Verified with imagemagick 6.7.7-10
  CompressionType = (
  UndefinedCompression,
  NoCompression,
  BZipCompression,
  DXT1Compression,
  DXT3Compression,
  DXT5Compression,
  FaxCompression,
  Group4Compression,
  JPEGCompression,
  JPEG2000Compression,      // ISO/IEC std 15444-1 */
  LosslessJPEGCompression,
  LZWCompression,
  RLECompression,
  ZipCompression,
  ZipSCompression,
  PizCompression,
  Pxr24Compression,
  B44Compression,
  B44ACompression,
  LZMACompression,            // Lempel-Ziv-Markov chain algorithm */
  JBIG1Compression,           // ISO/IEC std 11544 / ITU-T rec T.82 */
  JBIG2Compression,           // ISO/IEC std 14492 / ITU-T rec T.88 */
  ZstdCompression,
  WebPCompression
  );

  PCompressionType = ^CompressionType;
  
type
 DisposeType = (
  UnrecognizedDispose = 0,
  UndefinedDispose = 0,
  NoneDispose = 1,
  BackgroundDispose = 2,
  PreviousDispose = 3
  );

type
  PDisposeType = ^DisposeType;
  
type
 EndianType = (
  UndefinedEndian,
  LSBEndian,
  MSBEndian
 );

  PEndianType = ^EndianType;

type
 ExceptionType = (
  UndefinedException,
  WarningException = 300,
  ResourceLimitWarning = 300,
  TypeWarning = 305,
  OptionWarning = 310,
  DelegateWarning = 315,
  MissingDelegateWarning = 320,
  CorruptImageWarning = 325,
  FileOpenWarning = 330,
  BlobWarning = 335,
  StreamWarning = 340,
  CacheWarning = 345,
  CoderWarning = 350,
  FilterWarning = 352,
  ModuleWarning = 355,
  DrawWarning = 360,
  ImageWarning = 365,
  WandWarning = 370,
  RandomWarning = 375,
  XServerWarning = 380,
  MonitorWarning = 385,
  RegistryWarning = 390,
  ConfigureWarning = 395,
  PolicyWarning = 399,
  ErrorException = 400,
  ResourceLimitError = 400,
  TypeError = 405,
  OptionError = 410,
  DelegateError = 415,
  MissingDelegateError = 420,
  CorruptImageError = 425,
  FileOpenError = 430,
  BlobError = 435,
  StreamError = 440,
  CacheError = 445,
  CoderError = 450,
  FilterError = 452,
  ModuleError = 455,
  DrawError = 460,
  ImageError = 465,
  WandError = 470,
  RandomError = 475,
  XServerError = 480,
  MonitorError = 485,
  RegistryError = 490,
  ConfigureError = 495,
  PolicyError = 499,
  FatalErrorException = 700,
  ResourceLimitFatalError = 700,
  TypeFatalError = 705,
  OptionFatalError = 710,
  DelegateFatalError = 715,
  MissingDelegateFatalError = 720,
  CorruptImageFatalError = 725,
  FileOpenFatalError = 730,
  BlobFatalError = 735,
  StreamFatalError = 740,
  CacheFatalError = 745,
  CoderFatalError = 750,
  FilterFatalError = 752,
  ModuleFatalError = 755,
  DrawFatalError = 760,
  ImageFatalError = 765,
  WandFatalError = 770,
  RandomFatalError = 775,
  XServerFatalError = 780,
  MonitorFatalError = 785,
  RegistryFatalError = 790,
  ConfigureFatalError = 795,
  PolicyFatalError = 799
  );

type
  PExceptionType = ^ExceptionType;

type
 FilterType = (
  UndefinedFilter,
  PointFilter,
  BoxFilter,
  TriangleFilter,
  HermiteFilter,
  HanningFilter,
  HammingFilter,
  BlackmanFilter,
  GaussianFilter,
  QuadraticFilter,
  CubicFilter,
  CatromFilter,
  MitchellFilter,
  JincFilter,
  SincFilter,
  SincFastFilter,
  KaiserFilter,
  WelshFilter,
  ParzenFilter,
  BohmanFilter,
  BartlettFilter,
  LagrangeFilter,
  LanczosFilter,
  LanczosSharpFilter,
  Lanczos2Filter,
  Lanczos2SharpFilter,
  RobidouxFilter,
  RobidouxSharpFilter,
  CosineFilter,
  SplineFilter,
  LanczosRadiusFilter,
  SentinelFilter  // a count of all the filters, not a real filter */
 );

  PFilterType = ^FilterType;

type
 GravityType = (
  UndefinedGravity = 0,
  ForgetGravity = 0,
  NorthWestGravity = 1,
  NorthGravity = 2,
  NorthEastGravity = 3,
  WestGravity = 4,
  CenterGravity = 5,
  EastGravity = 6,
  SouthWestGravity = 7,
  SouthGravity = 8,
  SouthEastGravity = 9,
  StaticGravity = 10
  );

type
  PGravityType = ^GravityType;

type ImageType = (
  UndefinedType,
  BilevelType,
  GrayscaleType,
  GrayscaleMatteType,
  PaletteType,
  PaletteMatteType,
  TrueColorType,
  TrueColorMatteType,
  ColorSeparationType,
  ColorSeparationMatteType,
  OptimizeType,
  PaletteBilevelMatteType
 );

  PImageType = ^ImageType;

type
 InterlaceType = (
  UndefinedInterlace,
  NoInterlace,
  LineInterlace,
  PlaneInterlace,
  PartitionInterlace,
  GIFInterlace,
  JPEGInterlace,
  PNGInterlace
 );

  PInterlaceType = ^InterlaceType;

type
 OrientationType = (
  UndefinedOrientation,
  TopLeftOrientation,
  TopRightOrientation,
  BottomRightOrientation,
  BottomLeftOrientation,
  LeftTopOrientation,
  RightTopOrientation,
  RightBottomOrientation,
  LeftBottomOrientation
 );

  POrientationType = ^OrientationType;

type PreviewType = (
  UndefinedPreview,
  RotatePreview,
  ShearPreview,
  RollPreview,
  HuePreview,
  SaturationPreview,
  BrightnessPreview,
  GammaPreview,
  SpiffPreview,
  DullPreview,
  GrayscalePreview,
  QuantizePreview,
  DespecklePreview,
  ReduceNoisePreview,
  AddNoisePreview,
  SharpenPreview,
  BlurPreview,
  ThresholdPreview,
  EdgeDetectPreview,
  SpreadPreview,
  SolarizePreview,
  ShadePreview,
  RaisePreview,
  SegmentPreview,
  SwirlPreview,
  ImplodePreview,
  WavePreview,
  OilPaintPreview,
  CharcoalDrawingPreview,
  JPEGPreview
 );

  PPreviewType = ^PreviewType;

type RenderingIntent = (
  UndefinedIntent,
  SaturationIntent,
  PerceptualIntent,
  AbsoluteIntent,
  RelativeIntent
 );

  PRenderingIntent = ^RenderingIntent;

type ResolutionType = (
  UndefinedResolution,
  PixelsPerInchResolution,
  PixelsPerCentimeterResolution
 );

  PResolutionType = ^ResolutionType;

type TimerState = (
  UndefinedTimerState,
  StoppedTimerState,
  RunningTimerState
 );

  PTimerState = ^TimerState;

type
  AffineMatrix = record
    sx, rx, ry, sy, tx, ty: double;
  end;
  
  PAffineMatrix = ^AffineMatrix;

type
 IndexPacket = Quantum;

type
  PixelPacket = record
{$ifdef WORDS_BIGENDIAN}
   red, green, blue, opacity: Quantum;
{$else}
   blue, green, red, opacity: Quantum;
{$endif}
  end;
  
  PPixelPacket = ^PixelPacket;

type
  ColorPacket = record
   pixel: PixelPacket;
   index: IndexPacket;
   count: MagickSizeType;
  end;
  
  PColorPacket = ^ColorPacket;

type
  ErrorInfo = record
   mean_error_per_pixel, normalized_mean_error, normalized_maximum_error: double;
  end;

type
  PrimaryInfo = record
   x, y, z: double;
  end;

type 
  ProfileInfo = record
   name: PAnsiChar;
   length: culong;
   info: PAnsiChar;
   signature: culong;
  end;

  PProfileInfo = ^ProfileInfo;

type
  RectangleInfo = record
   width, height: culong;
   x, y: cint;
  end;

type
  SegmentInfo = record
   x1, y1, x2, y2: double;
  end;

type
  Timer = record
   start, stop, total: double;
  end;
  
  PTimer = ^Timer;

type
  TimerInfo = record
   user, elapsed: Timer;
   state: TimerState;
   signature: culong;
  end;
  
  PTimerInfo = ^TimerInfo;

type
  ChromaticityInfo = record
   red_primary, green_primary, blue_primary, white_point: PrimaryInfo;
 end;

type
  ExceptionInfo = record
   severity: ExceptionType;
   error_number: Shortint;
   reason, description: PAnsiChar;
	 exceptions: Pointer;
	 relinquish: MagickBooleanType;
   semaphore: Pointer; //PSemaphoreInfo;
   signature: culong;
  end;
  
  PExceptionInfo = ^ExceptionInfo;

//typedef struct _Ascii85Info _Ascii85Info_;

//typedef struct _BlobInfo _BlobInfo_;

type
  MagickProgressMonitor = function (const str: PAnsiChar; const para: MagickOffsetType;
   const sizetype: MagickSizeType; param: Pointer): PMagickBooleanType;

type
  PImage = ^Image;
  Image = record
   storage_class: ClassType;
   colorspace: ColorspaceType;
   compression: CompressionType;
   quality: culong;
   orientation: OrientationType;
   taint, matte: MagickBooleanType;
   columns, rows, depth, colors: culong;
   colormap: PPixelPacket;
   background_color, border_color, matte_color: PixelPacket;
   gamma: double;
   chromaticity: ChromaticityInfo;
   rendering_intent: RenderingIntent;
   profiles: Pointer;
   units: ResolutionType;
   montage, directory, geometry: PAnsiChar;
   offset: cint;
   x_resolution, y_resolution: double;
   page, extract_info, tile_info: RectangleInfo;  // deprecated
   bias, blur, fuzz: double;
   filter: FilterType;
   interlace: InterlaceType;
   endian: EndianType;
   gravity: GravityType;
   compose: CompositeOperator;
   dispose: DisposeType;
   clip_mask: PImage; // PImage
   scene, delay: culong;
   ticks_per_second: cint;
   iterations, total_colors: culong;
   start_loop: cint;
   error: ErrorInfo;
   timer: TimerInfo;
   progress_monitor: MagickProgressMonitor;
   client_data: Pointer;
   cache: Pointer;
   attributes: Pointer;
   ascii85: Pointer; //_Ascii85Info_
   blob: Pointer; // _BlobInfo_
   filename, magick_filename, magick: array[1..MaxTextExtent] of AnsiChar;
   magick_columns, magick_rows: culong;
   exception: ExceptionInfo;
   debug: MagickBooleanType;
   reference_count: Longint;
   semaphore: Pointer; //PSemaphoreInfo;
   color_profile, iptc_profile: ProfileInfo;
   generic_profile: PProfileInfo;
   generic_profiles: culong;  // this & ProfileInfo is deprecated
   signature: culong;
   previous, list, next: PImage;
 end;
 
// PImage = ^Image;

//type
//  size_t = PStreamHandler(procedure (const image: PImage;
//   const param: Pointer; const) );

type
  ImageInfo = record
   compression: CompressionType;
   orientation: OrientationType;
   temporary, adjoin, affirm, antialias: MagickBooleanType;
   size, extract, page, scenes: PAnsiChar;
   scene, number_scenes, depth: culong;
   interlace: InterlaceType;
   endian: EndianType;
   units: ResolutionType;
   quality: culong;
   sampling_factor, server_name, font, texture, density: PAnsiChar;
   pointsize, fuzz: double;
   background_color, border_color, matte_color: PixelPacket;
   dither, monochrome: MagickBooleanType;
   colors: culong;
   colorspace: ColorspaceType;
   type_: ImageType ;
   preview_type: PreviewType;
   group: cint;
   ping, verbose: MagickBooleanType;
   view, authenticate: PAnsiChar;
   channel: ChannelType;
   attributes: PImage;
   options: Pointer;
   progress_monitor: MagickProgressMonitor;
   client_data, cache: Pointer;
   stream: Pointer; //StreamHandler;
   file_: Pointer; // *file
   blob: Pointer;
   length: culong;
   magick, unique, zero, filename: array[1..MaxTextExtent] of AnsiChar;
   debug: MagickBooleanType;

  {
    Deprecated.
  }
   tile: PAnsiChar;
   subimage, subrange: culong;
   pen: PixelPacket;
   signature: culong;
 end;

  PImageInfo = ^ImageInfo;


