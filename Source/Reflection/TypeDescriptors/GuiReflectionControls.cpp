#include "GuiReflectionPlugin.h"
#include "../../Controls/Styles/GuiWin7Styles.h"
#include "../../Controls/Styles/GuiWin8Styles.h"

namespace vl
{
	namespace reflection
	{
		namespace description
		{
			using namespace presentation;
			using namespace presentation::controls;
			using namespace presentation::controls::list;
			using namespace presentation::controls::tree;
			using namespace presentation::elements::text;
			using namespace presentation::theme;

#ifndef VCZH_DEBUG_NO_REFLECTION

/***********************************************************************
Type Declaration
***********************************************************************/

#define _ ,

#define CONTROL_CONSTRUCTOR_CONTROLLER(CONTROL)\
	CLASS_MEMBER_CONSTRUCTOR(CONTROL*(CONTROL::IStyleController*), {L"styleController"})

#define CONTROL_CONSTRUCTOR_DEFAULT(CONTROL, CONSTRUCTOR)\
	CLASS_MEMBER_EXTERNALCTOR(CONTROL*(), NO_PARAMETER, CONSTRUCTOR)

#define CONTROL_CONSTRUCTOR_PROVIDER(CONTROL)\
	CLASS_MEMBER_CONSTRUCTOR(CONTROL*(CONTROL::IStyleProvider*), {L"styleProvider"})

#define INTERFACE_IDENTIFIER(INTERFACE)\
	CLASS_MEMBER_STATIC_EXTERNALMETHOD(GetIdentifier, NO_PARAMETER, WString(*)(), vl::reflection::description::Interface_GetIdentifier<::INTERFACE>)

			BEGIN_CLASS_MEMBER(GuiApplication)
				CLASS_MEMBER_STATIC_EXTERNALMETHOD(GetApplication, NO_PARAMETER, GuiApplication*(*)(), vl::presentation::controls::GetApplication)

				CLASS_MEMBER_PROPERTY_READONLY_FAST(MainWindow)
				CLASS_MEMBER_PROPERTY_READONLY_FAST(TooltipOwner)
				CLASS_MEMBER_PROPERTY_READONLY_FAST(ExecutablePath)
				CLASS_MEMBER_PROPERTY_READONLY_FAST(ExecutableFolder)
				CLASS_MEMBER_PROPERTY_READONLY_FAST(Windows)
				
				CLASS_MEMBER_METHOD(Run, NO_PARAMETER)
				CLASS_MEMBER_METHOD(ShowTooltip, {L"owner" _ L"tooltip" _ L"preferredContentWidth" _ L"location"})
				CLASS_MEMBER_METHOD(CloseTooltip, NO_PARAMETER)
				CLASS_MEMBER_METHOD(IsInMainThread, NO_PARAMETER)
				CLASS_MEMBER_METHOD(InvokeAsync, {L"proc"})
				CLASS_MEMBER_METHOD(InvokeInMainThread, {L"proc"})
				CLASS_MEMBER_METHOD(InvokeInMainThreadAndWait, {L"proc" _ L"milliseconds"})
				CLASS_MEMBER_METHOD(DelayExecute, {L"proc" _ L"milliseconds"})
				CLASS_MEMBER_METHOD(DelayExecuteInMainThread, {L"proc" _ L"milliseconds"})
			END_CLASS_MEMBER(GuiApplication)

			BEGIN_INTERFACE_MEMBER_NOPROXY(ITheme)
				CLASS_MEMBER_STATIC_EXTERNALMETHOD(GetCurrentTheme, NO_PARAMETER, ITheme*(*)(), vl::presentation::theme::GetCurrentTheme)
				CLASS_MEMBER_STATIC_EXTERNALMETHOD(SetCurrentTheme, {L"theme"}, void(*)(ITheme*), vl::presentation::theme::SetCurrentTheme)
				CLASS_MEMBER_STATIC_EXTERNALMETHOD(CreateWin7Theme, NO_PARAMETER, Ptr<ITheme>(*)(), vl::reflection::description::CreateWin7Theme)
				CLASS_MEMBER_STATIC_EXTERNALMETHOD(CreateWin8Theme, NO_PARAMETER, Ptr<ITheme>(*)(), vl::reflection::description::CreateWin8Theme)

				CLASS_MEMBER_METHOD(CreateWindowStyle, NO_PARAMETER)
				CLASS_MEMBER_METHOD(CreateCustomControlStyle, NO_PARAMETER)
				CLASS_MEMBER_METHOD(CreateTooltipStyle, NO_PARAMETER)
				CLASS_MEMBER_METHOD(CreateLabelStyle, NO_PARAMETER)
				CLASS_MEMBER_METHOD(CreateShortcutKeyStyle, NO_PARAMETER)
				CLASS_MEMBER_METHOD(CreateScrollContainerStyle, NO_PARAMETER)
				CLASS_MEMBER_METHOD(CreateGroupBoxStyle, NO_PARAMETER)
				CLASS_MEMBER_METHOD(CreateTabStyle, NO_PARAMETER)
				CLASS_MEMBER_METHOD(CreateComboBoxStyle, NO_PARAMETER)
				CLASS_MEMBER_METHOD(CreateMultilineTextBoxStyle, NO_PARAMETER)
				CLASS_MEMBER_METHOD(CreateTextBoxStyle, NO_PARAMETER)
				CLASS_MEMBER_METHOD(GetDefaultTextBoxColorEntry, NO_PARAMETER)
				CLASS_MEMBER_METHOD(CreateDocumentViewerStyle, NO_PARAMETER)
				CLASS_MEMBER_METHOD(CreateDocumentLabelStyle, NO_PARAMETER)
				CLASS_MEMBER_METHOD(CreateDocumentTextBoxStyle, NO_PARAMETER)
				CLASS_MEMBER_METHOD(CreateListViewStyle, NO_PARAMETER)
				CLASS_MEMBER_METHOD(CreateTreeViewStyle, NO_PARAMETER)
				CLASS_MEMBER_METHOD(CreateListItemBackgroundStyle, NO_PARAMETER)
				CLASS_MEMBER_METHOD(CreateTreeItemExpanderStyle, NO_PARAMETER)

				CLASS_MEMBER_METHOD(CreateMenuStyle, NO_PARAMETER)
				CLASS_MEMBER_METHOD(CreateMenuBarStyle, NO_PARAMETER)
				CLASS_MEMBER_METHOD(CreateMenuSplitterStyle, NO_PARAMETER)
				CLASS_MEMBER_METHOD(CreateMenuBarButtonStyle, NO_PARAMETER)
				CLASS_MEMBER_METHOD(CreateMenuItemButtonStyle, NO_PARAMETER)
				CLASS_MEMBER_METHOD(CreateToolBarStyle, NO_PARAMETER)
				CLASS_MEMBER_METHOD(CreateToolBarButtonStyle, NO_PARAMETER)
				CLASS_MEMBER_METHOD(CreateToolBarDropdownButtonStyle, NO_PARAMETER)
				CLASS_MEMBER_METHOD(CreateToolBarSplitButtonStyle, NO_PARAMETER)
				CLASS_MEMBER_METHOD(CreateToolBarSplitterStyle, NO_PARAMETER)

				CLASS_MEMBER_METHOD(CreateButtonStyle, NO_PARAMETER)
				CLASS_MEMBER_METHOD(CreateCheckBoxStyle, NO_PARAMETER)
				CLASS_MEMBER_METHOD(CreateRadioButtonStyle, NO_PARAMETER)
				CLASS_MEMBER_METHOD(CreateDatePickerStyle, NO_PARAMETER)

				CLASS_MEMBER_METHOD(CreateHScrollStyle, NO_PARAMETER)
				CLASS_MEMBER_METHOD(CreateVScrollStyle, NO_PARAMETER)
				CLASS_MEMBER_METHOD(CreateHTrackerStyle, NO_PARAMETER)
				CLASS_MEMBER_METHOD(CreateVTrackerStyle, NO_PARAMETER)
				CLASS_MEMBER_METHOD(CreateProgressBarStyle, NO_PARAMETER)
				CLASS_MEMBER_METHOD(GetScrollDefaultSize, NO_PARAMETER)
				CLASS_MEMBER_METHOD(GetTrackerDefaultSize, NO_PARAMETER)

				CLASS_MEMBER_METHOD(CreateTextListStyle, NO_PARAMETER)
				CLASS_MEMBER_METHOD(CreateCheckTextListItemStyle, NO_PARAMETER)
				CLASS_MEMBER_METHOD(CreateRadioTextListItemStyle, NO_PARAMETER)
			END_INTERFACE_MEMBER(ITheme)

			BEGIN_CLASS_MEMBER(GuiDialogBase)
				CLASS_MEMBER_BASE(GuiComponent)
			END_CLASS_MEMBER(GuiDialogBase)

			BEGIN_CLASS_MEMBER(GuiMessageDialog)
				CLASS_MEMBER_BASE(GuiDialogBase)
				CLASS_MEMBER_CONSTRUCTOR(GuiMessageDialog*(), NO_PARAMETER)

				CLASS_MEMBER_PROPERTY_FAST(Input)
				CLASS_MEMBER_PROPERTY_FAST(DefaultButton)
				CLASS_MEMBER_PROPERTY_FAST(Icon)
				CLASS_MEMBER_PROPERTY_FAST(ModalOption)
				CLASS_MEMBER_PROPERTY_FAST(Text)
				CLASS_MEMBER_PROPERTY_FAST(Title)

				CLASS_MEMBER_METHOD(ShowDialog, NO_PARAMETER)
			END_CLASS_MEMBER(GuiMessageDialog)

			BEGIN_CLASS_MEMBER(GuiColorDialog)
				CLASS_MEMBER_BASE(GuiDialogBase)
				CLASS_MEMBER_CONSTRUCTOR(GuiColorDialog*(), NO_PARAMETER)

				CLASS_MEMBER_PROPERTY_FAST(EnabledCustomColor)
				CLASS_MEMBER_PROPERTY_FAST(OpenedCustomColor)
				CLASS_MEMBER_PROPERTY_GUIEVENT_FAST(SelectedColor)
				CLASS_MEMBER_PROPERTY_READONLY_FAST(CustomColors)

				CLASS_MEMBER_METHOD(ShowDialog, NO_PARAMETER)
			END_CLASS_MEMBER(GuiColorDialog)

			BEGIN_CLASS_MEMBER(GuiFontDialog)
				CLASS_MEMBER_BASE(GuiDialogBase)
				CLASS_MEMBER_CONSTRUCTOR(GuiFontDialog*(), NO_PARAMETER)

				CLASS_MEMBER_PROPERTY_GUIEVENT_FAST(SelectedFont)
				CLASS_MEMBER_PROPERTY_GUIEVENT_FAST(SelectedColor)
				CLASS_MEMBER_PROPERTY_FAST(ShowSelection)
				CLASS_MEMBER_PROPERTY_FAST(ShowEffect)
				CLASS_MEMBER_PROPERTY_FAST(ForceFontExist)

				CLASS_MEMBER_METHOD(ShowDialog, NO_PARAMETER)
			END_CLASS_MEMBER(GuiFontDialog)

			BEGIN_CLASS_MEMBER(GuiFileDialogBase)
				CLASS_MEMBER_BASE(GuiDialogBase)

				CLASS_MEMBER_PROPERTY_FAST(Filter)
				CLASS_MEMBER_PROPERTY_GUIEVENT_FAST(FilterIndex)
				CLASS_MEMBER_PROPERTY_FAST(EnabledPreview)
				CLASS_MEMBER_PROPERTY_FAST(Title)
				CLASS_MEMBER_PROPERTY_GUIEVENT_FAST(FileName)
				CLASS_MEMBER_PROPERTY_FAST(Directory)
				CLASS_MEMBER_PROPERTY_FAST(DefaultExtension)
				CLASS_MEMBER_PROPERTY_FAST(Options)
			END_CLASS_MEMBER(GuiFileDialogBase)

			BEGIN_CLASS_MEMBER(GuiOpenFileDialog)
				CLASS_MEMBER_BASE(GuiFileDialogBase)
				CLASS_MEMBER_CONSTRUCTOR(GuiOpenFileDialog*(), NO_PARAMETER)

				CLASS_MEMBER_PROPERTY_READONLY_FAST(FileNames)
				CLASS_MEMBER_METHOD(ShowDialog, NO_PARAMETER)
			END_CLASS_MEMBER(GuiOpenFileDialog)

			BEGIN_CLASS_MEMBER(GuiSaveFileDialog)
				CLASS_MEMBER_BASE(GuiFileDialogBase)
				CLASS_MEMBER_CONSTRUCTOR(GuiSaveFileDialog*(), NO_PARAMETER)
				
				CLASS_MEMBER_METHOD(ShowDialog, NO_PARAMETER)
			END_CLASS_MEMBER(GuiSaveFileDialog)

			BEGIN_CLASS_MEMBER(GuiControl)
				CLASS_MEMBER_CONSTRUCTOR(GuiControl*(GuiControl::IStyleController*), {L"styleController"})

				CLASS_MEMBER_PROPERTY_READONLY_FAST(StyleController)
				CLASS_MEMBER_PROPERTY_READONLY_FAST(BoundsComposition)
				CLASS_MEMBER_PROPERTY_READONLY_FAST(ContainerComposition)
				CLASS_MEMBER_PROPERTY_READONLY_FAST(FocusableComposition)
				CLASS_MEMBER_PROPERTY_READONLY_FAST(Parent)
				CLASS_MEMBER_PROPERTY_READONLY_FAST(ChildrenCount)
				CLASS_MEMBER_PROPERTY_READONLY_FAST(RelatedControlHost)
				CLASS_MEMBER_PROPERTY_GUIEVENT_READONLY_FAST(VisuallyEnabled)
				CLASS_MEMBER_PROPERTY_GUIEVENT_FAST(Enabled)
				CLASS_MEMBER_PROPERTY_GUIEVENT_FAST(Visible)
				CLASS_MEMBER_PROPERTY_GUIEVENT_FAST(Alt)
				CLASS_MEMBER_PROPERTY_GUIEVENT_FAST(Text)
				CLASS_MEMBER_PROPERTY_GUIEVENT_FAST(Font)
				CLASS_MEMBER_PROPERTY_FAST(Tag)
				CLASS_MEMBER_PROPERTY_FAST(TooltipControl)
				CLASS_MEMBER_PROPERTY_FAST(TooltipWidth)

				CLASS_MEMBER_METHOD(SetActivatingAltHost, { L"host" })
				CLASS_MEMBER_METHOD(GetChild, {L"index"})
				CLASS_MEMBER_METHOD(AddChild, {L"control"})
				CLASS_MEMBER_METHOD(HasChild, {L"control"})
				CLASS_MEMBER_METHOD(SetFocus, NO_PARAMETER)
				CLASS_MEMBER_METHOD(DisplayTooltip, {L"location"})
				CLASS_MEMBER_METHOD(CloseTooltip, NO_PARAMETER)
				CLASS_MEMBER_METHOD_OVERLOAD(QueryService, {L"identifier"}, IDescriptable*(GuiControl::*)(const WString&))
			END_CLASS_MEMBER(GuiControl)

			BEGIN_INTERFACE_MEMBER(GuiControl::IStyleController)
				CLASS_MEMBER_METHOD(GetBoundsComposition, NO_PARAMETER)
				CLASS_MEMBER_METHOD(GetContainerComposition, NO_PARAMETER)
				CLASS_MEMBER_METHOD(SetFocusableComposition, {L"value"})
				CLASS_MEMBER_METHOD(SetText, {L"value"})
				CLASS_MEMBER_METHOD(SetFont, {L"value"})
				CLASS_MEMBER_METHOD(SetVisuallyEnabled, {L"value"})
			END_INTERFACE_MEMBER(GuiControl::IStyleController)

			BEGIN_INTERFACE_MEMBER(GuiControl::IStyleProvider)
				CLASS_MEMBER_METHOD(AssociateStyleController, {L"controller"})
				CLASS_MEMBER_METHOD(SetFocusableComposition, {L"value"})
				CLASS_MEMBER_METHOD(SetText, {L"value"})
				CLASS_MEMBER_METHOD(SetFont, {L"value"})
				CLASS_MEMBER_METHOD(SetVisuallyEnabled, {L"value"})
			END_INTERFACE_MEMBER(GuiControl::IStyleProvider)

			BEGIN_CLASS_MEMBER(GuiCustomControl)
				CLASS_MEMBER_BASE(GuiControl)
				CLASS_MEMBER_BASE(GuiInstanceRootObject)
				CONTROL_CONSTRUCTOR_CONTROLLER(GuiCustomControl)
			END_CLASS_MEMBER(GuiCustomControl)

			BEGIN_CLASS_MEMBER(GuiLabel)
				CLASS_MEMBER_BASE(GuiControl)
				CONTROL_CONSTRUCTOR_CONTROLLER(GuiLabel)

				CLASS_MEMBER_PROPERTY_FAST(TextColor)
			END_CLASS_MEMBER(GuiLabel)

			BEGIN_INTERFACE_MEMBER_NOPROXY(GuiLabel::IStyleController)
				CLASS_MEMBER_BASE(GuiControl::IStyleController)

				CLASS_MEMBER_METHOD(GetDefaultTextColor, NO_PARAMETER)
				CLASS_MEMBER_METHOD(SetTextColor, {L"value"})
			END_INTERFACE_MEMBER(GuiLabel::IStyleController)

			BEGIN_CLASS_MEMBER(GuiButton)
				CLASS_MEMBER_BASE(GuiControl)
				CONTROL_CONSTRUCTOR_CONTROLLER(GuiButton)

				CLASS_MEMBER_GUIEVENT(Clicked)

				CLASS_MEMBER_PROPERTY_FAST(ClickOnMouseUp)
			END_CLASS_MEMBER(GuiButton)

			BEGIN_INTERFACE_MEMBER_NOPROXY(GuiButton::IStyleController)
				CLASS_MEMBER_BASE(GuiControl::IStyleController)

				CLASS_MEMBER_METHOD(Transfer, {L"value"})
			END_INTERFACE_MEMBER(GuiButton::IStyleController)

			BEGIN_CLASS_MEMBER(GuiSelectableButton)
				CLASS_MEMBER_BASE(GuiButton)
				CONTROL_CONSTRUCTOR_CONTROLLER(GuiSelectableButton)

				CLASS_MEMBER_PROPERTY_GUIEVENT_FAST(GroupController)
				CLASS_MEMBER_PROPERTY_GUIEVENT_FAST(AutoSelection)
				CLASS_MEMBER_PROPERTY_GUIEVENT_FAST(Selected)
			END_CLASS_MEMBER(GuiSelectableButton)

			BEGIN_INTERFACE_MEMBER_NOPROXY(GuiSelectableButton::IStyleController)
				CLASS_MEMBER_BASE(GuiButton::IStyleController)

				CLASS_MEMBER_METHOD(SetSelected, {L"value"})
			END_INTERFACE_MEMBER(GuiSelectableButton::IStyleController)

			BEGIN_CLASS_MEMBER(GuiSelectableButton::GroupController)
				CLASS_MEMBER_BASE(GuiComponent)

				CLASS_MEMBER_METHOD(Attach, {L"button"})
				CLASS_MEMBER_METHOD(Detach, {L"button"})
				CLASS_MEMBER_METHOD(OnSelectedChanged, {L"button"})
			END_CLASS_MEMBER(GuiSelectableButton::GroupController)

			BEGIN_CLASS_MEMBER(GuiSelectableButton::MutexGroupController)
				CLASS_MEMBER_BASE(GuiSelectableButton::GroupController)
				CLASS_MEMBER_CONSTRUCTOR(GuiSelectableButton::MutexGroupController*(), NO_PARAMETER)
			END_CLASS_MEMBER(GuiSelectableButton::MutexGroupController)

			BEGIN_CLASS_MEMBER(GuiScroll)
				CLASS_MEMBER_BASE(GuiControl)
				CONTROL_CONSTRUCTOR_CONTROLLER(GuiScroll)

				CLASS_MEMBER_PROPERTY_GUIEVENT_FAST(TotalSize)
				CLASS_MEMBER_PROPERTY_GUIEVENT_FAST(PageSize)
				CLASS_MEMBER_PROPERTY_GUIEVENT_FAST(Position)
				CLASS_MEMBER_PROPERTY_GUIEVENT_FAST(SmallMove)
				CLASS_MEMBER_PROPERTY_GUIEVENT_FAST(BigMove)
				CLASS_MEMBER_PROPERTY_READONLY_FAST(MinPosition)
				CLASS_MEMBER_PROPERTY_READONLY_FAST(MaxPosition)
			END_CLASS_MEMBER(GuiScroll)

			BEGIN_INTERFACE_MEMBER_NOPROXY(GuiScroll::IStyleController)
				CLASS_MEMBER_BASE(GuiControl::IStyleController)

				CLASS_MEMBER_METHOD(SetCommandExecutor, {L"value"})
				CLASS_MEMBER_METHOD(SetTotalSize, {L"value"})
				CLASS_MEMBER_METHOD(SetPageSize, {L"value"})
				CLASS_MEMBER_METHOD(SetPosition, {L"value"})
			END_INTERFACE_MEMBER(GuiScroll::IStyleController)

			BEGIN_CLASS_MEMBER(GuiTabPage)
				CLASS_MEMBER_BASE(GuiCustomControl)
				CONTROL_CONSTRUCTOR_CONTROLLER(GuiTabPage)
				CONTROL_CONSTRUCTOR_DEFAULT(GuiTabPage, vl::presentation::theme::g::NewTabPage)
			END_CLASS_MEMBER(GuiTabPage)

			BEGIN_CLASS_MEMBER(GuiTab)
				CLASS_MEMBER_BASE(GuiControl)
				CONTROL_CONSTRUCTOR_CONTROLLER(GuiTab)
				CONTROL_CONSTRUCTOR_DEFAULT(GuiTab, vl::presentation::theme::g::NewTab)

				CLASS_MEMBER_PROPERTY_GUIEVENT_FAST(SelectedPage)

				CLASS_MEMBER_PROPERTY_READONLY_FAST(Pages)
			END_CLASS_MEMBER(GuiTab)

			BEGIN_INTERFACE_MEMBER_NOPROXY(GuiTab::IStyleController)
				CLASS_MEMBER_BASE(GuiControl::IStyleController)

				CLASS_MEMBER_METHOD(SetCommandExecutor, {L"value"})
				CLASS_MEMBER_METHOD(InsertTab, {L"index"})
				CLASS_MEMBER_METHOD(SetTabText, {L"index" _ L"value"})
				CLASS_MEMBER_METHOD(RemoveTab, {L"index"})
				CLASS_MEMBER_METHOD(SetSelectedTab, {L"index"})
				CLASS_MEMBER_METHOD(SetTabAlt, {L"index" _ L"value"})
				CLASS_MEMBER_METHOD(GetTabAltAction, {L"index"})
			END_INTERFACE_MEMBER(GuiTab::IStyleController)

			BEGIN_CLASS_MEMBER(GuiScrollView)
				CLASS_MEMBER_BASE(GuiControl)

				CLASS_MEMBER_PROPERTY_READONLY_FAST(ViewSize)
				CLASS_MEMBER_PROPERTY_READONLY_FAST(ViewBounds)
				CLASS_MEMBER_PROPERTY_READONLY_FAST(HorizontalScroll)
				CLASS_MEMBER_PROPERTY_READONLY_FAST(VerticalScroll)
				CLASS_MEMBER_PROPERTY_FAST(HorizontalAlwaysVisible)
				CLASS_MEMBER_PROPERTY_FAST(VerticalAlwaysVisible)

				CLASS_MEMBER_METHOD(CalculateView, NO_PARAMETER)
			END_CLASS_MEMBER(GuiScrollView)

			BEGIN_INTERFACE_MEMBER_NOPROXY(GuiScrollView::IStyleProvider)
				CLASS_MEMBER_BASE(GuiControl::IStyleProvider)

				CLASS_MEMBER_METHOD(CreateHorizontalScrollStyle, NO_PARAMETER)
				CLASS_MEMBER_METHOD(CreateVerticalScrollStyle, NO_PARAMETER)
				CLASS_MEMBER_METHOD(GetDefaultScrollSize, NO_PARAMETER)
				CLASS_MEMBER_METHOD(InstallBackground, {L"boundsComposition"})
			END_INTERFACE_MEMBER(GuiScrollView::IStyleProvider)

			BEGIN_CLASS_MEMBER(GuiScrollContainer)
				CLASS_MEMBER_BASE(GuiScrollView)
				CONTROL_CONSTRUCTOR_PROVIDER(GuiScrollContainer)

				CLASS_MEMBER_PROPERTY_FAST(ExtendToFullWidth)
			END_CLASS_MEMBER(GuiScrollContainer)

			BEGIN_CLASS_MEMBER(GuiControlHost)
				CLASS_MEMBER_BASE(GuiControl)
				CLASS_MEMBER_BASE(GuiInstanceRootObject)
				CLASS_MEMBER_CONSTRUCTOR(GuiControlHost*(GuiControl::IStyleController*), {L"styleController"})

				CLASS_MEMBER_GUIEVENT(WindowGotFocus)
				CLASS_MEMBER_GUIEVENT(WindowLostFocus)
				CLASS_MEMBER_GUIEVENT(WindowActivated)
				CLASS_MEMBER_GUIEVENT(WindowDeactivated)
				CLASS_MEMBER_GUIEVENT(WindowOpened)
				CLASS_MEMBER_GUIEVENT(WindowClosing)
				CLASS_MEMBER_GUIEVENT(WindowClosed)
				CLASS_MEMBER_GUIEVENT(WindowDestroying)

				CLASS_MEMBER_PROPERTY_READONLY_FAST(MainComposition)
				CLASS_MEMBER_PROPERTY_FAST(ShowInTaskBar)
				CLASS_MEMBER_PROPERTY_FAST(EnabledActivate)
				CLASS_MEMBER_PROPERTY_FAST(TopMost)
				CLASS_MEMBER_PROPERTY_FAST(ClientSize)
				CLASS_MEMBER_PROPERTY_FAST(Bounds)
				CLASS_MEMBER_PROPERTY_FAST(ShortcutKeyManager)
				CLASS_MEMBER_PROPERTY_READONLY_FAST(AnimationManager)

				CLASS_MEMBER_METHOD(ForceCalculateSizeImmediately, NO_PARAMETER)
				CLASS_MEMBER_METHOD(GetFocused, NO_PARAMETER)
				CLASS_MEMBER_METHOD(SetFocused, NO_PARAMETER)
				CLASS_MEMBER_METHOD(GetActivated, NO_PARAMETER)
				CLASS_MEMBER_METHOD(SetActivated, NO_PARAMETER)
				CLASS_MEMBER_METHOD(Show, NO_PARAMETER)
				CLASS_MEMBER_METHOD(ShowDeactivated, NO_PARAMETER)
				CLASS_MEMBER_METHOD(ShowRestored, NO_PARAMETER)
				CLASS_MEMBER_METHOD(ShowMaximized, NO_PARAMETER)
				CLASS_MEMBER_METHOD(ShowMinimized, NO_PARAMETER)
				CLASS_MEMBER_METHOD(Hide, NO_PARAMETER)
				CLASS_MEMBER_METHOD(Close, NO_PARAMETER)
				CLASS_MEMBER_METHOD(GetOpening, NO_PARAMETER)
			END_CLASS_MEMBER(GuiControlHost)

			BEGIN_CLASS_MEMBER(GuiWindow)
				CLASS_MEMBER_BASE(GuiControlHost)
				CONTROL_CONSTRUCTOR_CONTROLLER(GuiWindow)

				CLASS_MEMBER_GUIEVENT(ClipboardUpdated)

				CLASS_MEMBER_PROPERTY_FAST(MaximizedBox)
				CLASS_MEMBER_PROPERTY_FAST(MinimizedBox)
				CLASS_MEMBER_PROPERTY_FAST(Border)
				CLASS_MEMBER_PROPERTY_FAST(SizeBox)
				CLASS_MEMBER_PROPERTY_FAST(IconVisible)
				CLASS_MEMBER_PROPERTY_FAST(TitleBar)

				CLASS_MEMBER_METHOD(MoveToScreenCenter, NO_PARAMETER)
				CLASS_MEMBER_METHOD(ShowModal, { L"owner" _ L"callback" })
				CLASS_MEMBER_METHOD(ShowModalAndDelete, { L"owner" _ L"callback" })
				CLASS_MEMBER_METHOD(ShowModalAsync, { L"owner" })
			END_CLASS_MEMBER(GuiWindow)

			BEGIN_INTERFACE_MEMBER_NOPROXY(GuiWindow::IStyleController)
				CLASS_MEMBER_BASE(GuiControl::IStyleController)

				CLASS_MEMBER_METHOD(AttachWindow, {L"window"})
				CLASS_MEMBER_METHOD(InitializeNativeWindowProperties, NO_PARAMETER)
				CLASS_MEMBER_METHOD(SetSizeState, {L"value"})

				CLASS_MEMBER_PROPERTY_FAST(MaximizedBox)
				CLASS_MEMBER_PROPERTY_FAST(MinimizedBox)
				CLASS_MEMBER_PROPERTY_FAST(Border)
				CLASS_MEMBER_PROPERTY_FAST(SizeBox)
				CLASS_MEMBER_PROPERTY_FAST(IconVisible)
				CLASS_MEMBER_PROPERTY_FAST(TitleBar)

				CLASS_MEMBER_METHOD(CreateTooltipStyle, NO_PARAMETER)
				CLASS_MEMBER_METHOD(CreateShortcutKeyStyle, NO_PARAMETER)
			END_INTERFACE_MEMBER(GuiWindow::IStyleController)

			BEGIN_CLASS_MEMBER(GuiPopup)
				CLASS_MEMBER_BASE(GuiWindow)
				CONTROL_CONSTRUCTOR_CONTROLLER(GuiPopup)

				CLASS_MEMBER_METHOD(IsClippedByScreen, {L"location"})
				CLASS_MEMBER_METHOD_OVERLOAD(ShowPopup, {L"location" _ L"screen"}, void(GuiPopup::*)(Point _ INativeScreen*))
				CLASS_MEMBER_METHOD_OVERLOAD(ShowPopup, {L"control" _ L"location"}, void(GuiPopup::*)(GuiControl* _ Point))
				CLASS_MEMBER_METHOD_OVERLOAD(ShowPopup, {L"control" _ L"preferredTopBottomSide"}, void(GuiPopup::*)(GuiControl* _ bool))
			END_CLASS_MEMBER(GuiPopup)

			BEGIN_CLASS_MEMBER(GuiTooltip)
				CLASS_MEMBER_BASE(GuiPopup)
				CONTROL_CONSTRUCTOR_CONTROLLER(GuiTooltip)
				
				CLASS_MEMBER_PROPERTY_FAST(PreferredContentWidth)
				CLASS_MEMBER_PROPERTY_FAST(TemporaryContentControl)
			END_CLASS_MEMBER(GuiTooltip)

			BEGIN_CLASS_MEMBER(GuiListControl)
				CLASS_MEMBER_BASE(GuiScrollView)
				CLASS_MEMBER_CONSTRUCTOR(GuiListControl*(GuiListControl::IStyleProvider* _ GuiListControl::IItemProvider* _ bool), {L"styleProvider" _ L"itemProvider" _ L"acceptFocus"})

				CLASS_MEMBER_GUIEVENT(AdoptedSizeInvalidated)
				CLASS_MEMBER_GUIEVENT(ItemLeftButtonDown)
				CLASS_MEMBER_GUIEVENT(ItemLeftButtonUp)
				CLASS_MEMBER_GUIEVENT(ItemLeftButtonDoubleClick)
				CLASS_MEMBER_GUIEVENT(ItemMiddleButtonDown)
				CLASS_MEMBER_GUIEVENT(ItemMiddleButtonUp)
				CLASS_MEMBER_GUIEVENT(ItemMiddleButtonDoubleClick)
				CLASS_MEMBER_GUIEVENT(ItemRightButtonDown)
				CLASS_MEMBER_GUIEVENT(ItemRightButtonUp)
				CLASS_MEMBER_GUIEVENT(ItemRightButtonDoubleClick)
				CLASS_MEMBER_GUIEVENT(ItemMouseMove)
				CLASS_MEMBER_GUIEVENT(ItemMouseEnter)
				CLASS_MEMBER_GUIEVENT(ItemMouseLeave)

				CLASS_MEMBER_PROPERTY_READONLY_FAST(ItemProvider)
				CLASS_MEMBER_PROPERTY_GUIEVENT_FAST(ItemTemplate)
				CLASS_MEMBER_PROPERTY_GUIEVENT_FAST(Arranger)
				CLASS_MEMBER_PROPERTY_GUIEVENT_FAST(Axis)

				CLASS_MEMBER_METHOD(EnsureItemVisible, {L"itemIndex"})
				CLASS_MEMBER_METHOD(GetAdoptedSize, {L"expectedSize"})
			END_CLASS_MEMBER(GuiListControl)

			BEGIN_INTERFACE_MEMBER(GuiListControl::IItemProviderCallback)
				CLASS_MEMBER_BASE(IDescriptable)

				CLASS_MEMBER_METHOD(OnAttached, {L"provider"})
				CLASS_MEMBER_METHOD(OnItemModified, {L"start" _ L"count" _ L"newCount"})
			END_INTERFACE_MEMBER(GuiListControl::IItemProviderCallback)

			BEGIN_INTERFACE_MEMBER_NOPROXY(GuiListControl::IItemArrangerCallback)
				CLASS_MEMBER_BASE(IDescriptable)
				CLASS_MEMBER_METHOD(RequestItem, {L"itemIndex"})
				CLASS_MEMBER_METHOD(ReleaseItem, {L"style"})
				CLASS_MEMBER_METHOD(SetViewLocation, {L"value"})
				CLASS_MEMBER_METHOD(GetStylePreferredSize, {L"style"})
				CLASS_MEMBER_METHOD(SetStyleAlignmentToParent, {L"style" _ L"margin"})
				CLASS_MEMBER_METHOD(GetStyleBounds, {L"style"})
				CLASS_MEMBER_METHOD(SetStyleBounds, {L"style" _ L"bounds"})
				CLASS_MEMBER_METHOD(GetContainerComposition, NO_PARAMETER)
				CLASS_MEMBER_METHOD(OnTotalSizeChanged, NO_PARAMETER)
			END_INTERFACE_MEMBER(GuiListControl::IItemArrangerCallback)

			BEGIN_INTERFACE_MEMBER(GuiListControl::IItemProvider)
				CLASS_MEMBER_BASE(IDescriptable)

				CLASS_MEMBER_METHOD(AttachCallback, {L"value"})
				CLASS_MEMBER_METHOD(DetachCallback, {L"value"})
				CLASS_MEMBER_METHOD(PushEditing, NO_PARAMETER)
				CLASS_MEMBER_METHOD(PopEditing, NO_PARAMETER)
				CLASS_MEMBER_METHOD(IsEditing, NO_PARAMETER)
				CLASS_MEMBER_METHOD(Count, NO_PARAMETER)
				CLASS_MEMBER_METHOD(GetTextValue, { L"itemIndex" })
				CLASS_MEMBER_METHOD(GetBindingValue, { L"itemIndex" })
				CLASS_MEMBER_METHOD(RequestView, {L"identifier"})
			END_INTERFACE_MEMBER(GuiListControl::IItemProvider)

			BEGIN_INTERFACE_MEMBER(GuiListControl::IItemArranger)
				CLASS_MEMBER_BASE(GuiListControl::IItemProviderCallback)

				CLASS_MEMBER_PROPERTY_FAST(Callback)
				CLASS_MEMBER_PROPERTY_READONLY_FAST(TotalSize)
				
				CLASS_MEMBER_METHOD(AttachListControl, {L"value"})
				CLASS_MEMBER_METHOD(DetachListControl, NO_PARAMETER)
				CLASS_MEMBER_METHOD(GetVisibleStyle, {L"itemIndex"})
				CLASS_MEMBER_METHOD(GetVisibleIndex, {L"style"})
				CLASS_MEMBER_METHOD(OnViewChanged, {L"bounds"})
				CLASS_MEMBER_METHOD(FindItem, {L"itemIndex" _ L"key"})
				CLASS_MEMBER_METHOD(EnsureItemVisible, {L"itemIndex"})
				CLASS_MEMBER_METHOD(GetAdoptedSize, {L"expectedSize"})
			END_INTERFACE_MEMBER(GuiListControl::IItemArranger)

			BEGIN_CLASS_MEMBER(GuiSelectableListControl)
				CLASS_MEMBER_BASE(GuiListControl)
				CLASS_MEMBER_CONSTRUCTOR(GuiSelectableListControl*(GuiSelectableListControl::IStyleProvider* _ GuiSelectableListControl::IItemProvider*), {L"styleProvider" _ L"itemProvider"})

				CLASS_MEMBER_GUIEVENT(SelectionChanged)

				CLASS_MEMBER_PROPERTY_FAST(MultiSelect)
				CLASS_MEMBER_PROPERTY_EVENT_READONLY_FAST(SelectedItems, SelectionChanged)
				CLASS_MEMBER_PROPERTY_EVENT_READONLY_FAST(SelectedItemIndex, SelectionChanged)
				CLASS_MEMBER_PROPERTY_EVENT_READONLY_FAST(SelectedItemText, SelectionChanged)

				CLASS_MEMBER_METHOD(GetSelected, {L"itemIndex"})
				CLASS_MEMBER_METHOD(SetSelected, {L"itemIndex" _ L"value"})
				CLASS_MEMBER_METHOD(SelectItemsByClick, {L"itemIndex" _ L"ctrl" _ L"shift" _ L"leftButton"})
				CLASS_MEMBER_METHOD(SelectItemsByKey, {L"code" _ L"ctrl" _ L"shift"})
				CLASS_MEMBER_METHOD(ClearSelection, NO_PARAMETER)
			END_CLASS_MEMBER(GuiSelectableListControl)

			BEGIN_CLASS_MEMBER(RangedItemArrangerBase)
				CLASS_MEMBER_BASE(GuiListControl::IItemArranger)
			END_CLASS_MEMBER(RangedItemArrangerBase)

			BEGIN_CLASS_MEMBER(FixedHeightItemArranger)
				CLASS_MEMBER_BASE(RangedItemArrangerBase)
				CLASS_MEMBER_CONSTRUCTOR(Ptr<FixedHeightItemArranger>(), NO_PARAMETER)
			END_CLASS_MEMBER(FixedHeightItemArranger)

			BEGIN_CLASS_MEMBER(FixedSizeMultiColumnItemArranger)
				CLASS_MEMBER_BASE(RangedItemArrangerBase)
				CLASS_MEMBER_CONSTRUCTOR(Ptr<FixedSizeMultiColumnItemArranger>(), NO_PARAMETER)
			END_CLASS_MEMBER(FixedSizeMultiColumnItemArranger)

			BEGIN_CLASS_MEMBER(FixedHeightMultiColumnItemArranger)
				CLASS_MEMBER_BASE(RangedItemArrangerBase)
				CLASS_MEMBER_CONSTRUCTOR(Ptr<FixedHeightMultiColumnItemArranger>(), NO_PARAMETER)
			END_CLASS_MEMBER(FixedHeightMultiColumnItemArranger)

			BEGIN_INTERFACE_MEMBER(ITextItemView)
				INTERFACE_IDENTIFIER(vl::presentation::controls::list::ITextItemView)

				CLASS_MEMBER_METHOD(GetChecked, {L"itemIndex"})
				CLASS_MEMBER_METHOD(SetChecked, {L"itemIndex" _ L"value"})
			END_INTERFACE_MEMBER(ITextItemView)

			BEGIN_CLASS_MEMBER(TextItem)
				CLASS_MEMBER_CONSTRUCTOR(Ptr<TextItem>(), NO_PARAMETER)
				CLASS_MEMBER_CONSTRUCTOR(Ptr<TextItem>(const WString&), {L"text"})
				CLASS_MEMBER_CONSTRUCTOR(Ptr<TextItem>(const WString&, bool), {L"text" _ L"checked"})

				CLASS_MEMBER_PROPERTY_FAST(Text)
				CLASS_MEMBER_PROPERTY_FAST(Checked)
			END_CLASS_MEMBER(TextItem)

			BEGIN_ENUM_ITEM(TextListView)
				ENUM_CLASS_ITEM(Text)
				ENUM_CLASS_ITEM(Check)
				ENUM_CLASS_ITEM(Radio)
				ENUM_CLASS_ITEM(Unknown)
			END_ENUM_ITEM(TextListView)

			BEGIN_CLASS_MEMBER(GuiVirtualTextList)
				CLASS_MEMBER_BASE(GuiSelectableListControl)
				CLASS_MEMBER_CONSTRUCTOR(GuiVirtualTextList*(GuiVirtualTextList::IStyleProvider* _ GuiListControl::IItemProvider*), {L"styleProvider" _ L"itemProvider"})

				CLASS_MEMBER_GUIEVENT(ItemChecked)
				CLASS_MEMBER_PROPERTY_READONLY_FAST(TextListStyleProvider)
				CLASS_MEMBER_PROPERTY_FAST(View)
			END_CLASS_MEMBER(GuiVirtualTextList)

			BEGIN_INTERFACE_MEMBER_NOPROXY(GuiVirtualTextList::IStyleProvider)
				CLASS_MEMBER_BASE(GuiSelectableListControl::IStyleProvider)

				CLASS_MEMBER_PROPERTY_READONLY_FAST(TextColor)
			END_INTERFACE_MEMBER(GuiVirtualTextList::IStyleProvider)

			BEGIN_CLASS_MEMBER(GuiTextList)
				CLASS_MEMBER_BASE(GuiVirtualTextList)
				CLASS_MEMBER_CONSTRUCTOR(GuiTextList*(GuiVirtualTextList::IStyleProvider*), { L"styleProvider" })

				CLASS_MEMBER_PROPERTY_READONLY_FAST(Items)
				CLASS_MEMBER_PROPERTY_EVENT_READONLY_FAST(SelectedItem, SelectionChanged)
			END_CLASS_MEMBER(GuiTextList)

			BEGIN_CLASS_MEMBER(GuiListViewColumnHeader)
				CLASS_MEMBER_BASE(GuiMenuButton)
				CONTROL_CONSTRUCTOR_CONTROLLER(GuiListViewColumnHeader)

				CLASS_MEMBER_PROPERTY_FAST(ColumnSortingState)
			END_CLASS_MEMBER(GuiListViewColumnHeader)

			BEGIN_INTERFACE_MEMBER_NOPROXY(GuiListViewColumnHeader::IStyleController)
				CLASS_MEMBER_BASE(GuiMenuButton::IStyleController)

				CLASS_MEMBER_METHOD(SetColumnSortingState, {L"value"})
			END_INTERFACE_MEMBER(GuiListViewColumnHeader::IStyleController)

			BEGIN_CLASS_MEMBER(GuiListViewBase)
				CLASS_MEMBER_BASE(GuiSelectableListControl)
				CLASS_MEMBER_CONSTRUCTOR(GuiListViewBase*(GuiListViewBase::IStyleProvider* _ GuiListControl::IItemProvider*), {L"styleProvider" _ L"itemProvider"})

				CLASS_MEMBER_GUIEVENT(ColumnClicked)

				CLASS_MEMBER_METHOD(GetListViewStyleProvider, NO_PARAMETER)
			END_CLASS_MEMBER(GuiListViewBase)

			BEGIN_INTERFACE_MEMBER_NOPROXY(GuiListViewBase::IStyleProvider)
				CLASS_MEMBER_BASE(GuiSelectableListControl::IStyleProvider)

				CLASS_MEMBER_PROPERTY_READONLY_FAST(PrimaryTextColor)
				CLASS_MEMBER_PROPERTY_READONLY_FAST(SecondaryTextColor)
				CLASS_MEMBER_PROPERTY_READONLY_FAST(ItemSeparatorColor)

				CLASS_MEMBER_METHOD(CreateItemBackground, NO_PARAMETER)
				CLASS_MEMBER_METHOD(CreateColumnStyle, NO_PARAMETER)
			END_INTERFACE_MEMBER(GuiListViewBase::IStyleProvider)

			BEGIN_INTERFACE_MEMBER(IListViewItemView)
				INTERFACE_IDENTIFIER(vl::presentation::controls::list::IListViewItemView)

				CLASS_MEMBER_METHOD(GetSmallImage, {L"itemIndex"})
				CLASS_MEMBER_METHOD(GetLargeImage, {L"itemIndex"})
				CLASS_MEMBER_METHOD(GetText, {L"itemIndex"})
				CLASS_MEMBER_METHOD(GetSubItem, {L"itemIndex" _ L"index"})
				CLASS_MEMBER_METHOD(GetDataColumnCount, NO_PARAMETER)
				CLASS_MEMBER_METHOD(GetDataColumn, {L"index"})
				CLASS_MEMBER_METHOD(GetColumnCount, NO_PARAMETER)
				CLASS_MEMBER_METHOD(GetColumnText, {L"index"})
			END_INTERFACE_MEMBER(ListViewItemStyleProvider::IListViewItemView)

			BEGIN_CLASS_MEMBER(ListViewColumnItemArranger)
				CLASS_MEMBER_BASE(FixedHeightItemArranger)
				CLASS_MEMBER_CONSTRUCTOR(Ptr<ListViewColumnItemArranger>(), NO_PARAMETER)
			END_CLASS_MEMBER(ListViewColumnItemArranger)

			BEGIN_CLASS_MEMBER(ListViewColumnItemArranger::IColumnItemViewCallback)
				CLASS_MEMBER_METHOD(OnColumnChanged, NO_PARAMETER)
			END_CLASS_MEMBER(ListViewColumnItemArranger::IColumnItemViewCallback)

			BEGIN_INTERFACE_MEMBER(ListViewColumnItemArranger::IColumnItemView)
				CLASS_MEMBER_BASE(IDescriptable)
				INTERFACE_IDENTIFIER(vl::presentation::controls::list::ListViewColumnItemArranger::IColumnItemView)

				CLASS_MEMBER_METHOD(AttachCallback, {L"value"})
				CLASS_MEMBER_METHOD(DetachCallback, {L"value"})
				CLASS_MEMBER_METHOD(GetColumnSize, {L"index"})
				CLASS_MEMBER_METHOD(SetColumnSize, {L"index" _ L"value"})
				CLASS_MEMBER_METHOD(GetDropdownPopup, {L"index"})
				CLASS_MEMBER_METHOD(GetSortingState, {L"index"})
			END_INTERFACE_MEMBER(ListViewColumnItemArranger::IColumnItemView)

			BEGIN_CLASS_MEMBER(ListViewItem)
				CLASS_MEMBER_CONSTRUCTOR(Ptr<ListViewItem>(), NO_PARAMETER)

				CLASS_MEMBER_PROPERTY_FAST(SmallImage)
				CLASS_MEMBER_PROPERTY_FAST(LargeImage)
				CLASS_MEMBER_PROPERTY_FAST(Text)
				CLASS_MEMBER_PROPERTY_READONLY_FAST(SubItems)
				CLASS_MEMBER_PROPERTY_FAST(Tag)
			END_CLASS_MEMBER(ListViewItem)

			BEGIN_CLASS_MEMBER(ListViewColumn)
				CLASS_MEMBER_CONSTRUCTOR(Ptr<ListViewColumn>(), NO_PARAMETER)
				CLASS_MEMBER_CONSTRUCTOR(Ptr<ListViewColumn>(const WString&), {L"text"})
				CLASS_MEMBER_CONSTRUCTOR(Ptr<ListViewColumn>(const WString&, vint), {L"text" _ L"size"})

				CLASS_MEMBER_PROPERTY_FAST(Text)
				CLASS_MEMBER_PROPERTY_FAST(TextProperty)
				CLASS_MEMBER_PROPERTY_FAST(Size)
				CLASS_MEMBER_PROPERTY_FAST(DropdownPopup)
				CLASS_MEMBER_PROPERTY_FAST(SortingState)
			END_CLASS_MEMBER(ListViewColumn)

			BEGIN_ENUM_ITEM(ListViewView)
				ENUM_CLASS_ITEM(BigIcon)
				ENUM_CLASS_ITEM(SmallIcon)
				ENUM_CLASS_ITEM(List)
				ENUM_CLASS_ITEM(Tile)
				ENUM_CLASS_ITEM(Information)
				ENUM_CLASS_ITEM(Detail)
				ENUM_CLASS_ITEM(Unknown)
			END_ENUM_ITEM(ListViewView)

			BEGIN_CLASS_MEMBER(GuiVirtualListView)
				CLASS_MEMBER_BASE(GuiListViewBase)
				CLASS_MEMBER_CONSTRUCTOR(GuiVirtualListView*(GuiVirtualListView::IStyleProvider*, GuiListControl::IItemProvider*), { L"styleProvider" _ L"itemProvider" })

				CLASS_MEMBER_PROPERTY_FAST(View)
			END_CLASS_MEMBER(GuiVirtualListView)

			BEGIN_CLASS_MEMBER(GuiListView)
				CLASS_MEMBER_BASE(GuiVirtualListView)
				CONTROL_CONSTRUCTOR_PROVIDER(GuiListView)

				CLASS_MEMBER_PROPERTY_READONLY_FAST(DataColumns)
				CLASS_MEMBER_PROPERTY_READONLY_FAST(Columns)
				CLASS_MEMBER_PROPERTY_READONLY_FAST(Items)
				CLASS_MEMBER_PROPERTY_EVENT_READONLY_FAST(SelectedItem, SelectionChanged)
			END_CLASS_MEMBER(GuiListView)

			BEGIN_INTERFACE_MEMBER_NOPROXY(IGuiMenuService)
				INTERFACE_IDENTIFIER(vl::presentation::controls::IGuiMenuService)

				CLASS_MEMBER_METHOD(GetParentMenuService, NO_PARAMETER)
				CLASS_MEMBER_METHOD(GetPreferredDirection, NO_PARAMETER)
				CLASS_MEMBER_METHOD(IsActiveState, NO_PARAMETER)
				CLASS_MEMBER_METHOD(IsSubMenuActivatedByMouseDown, NO_PARAMETER)
				CLASS_MEMBER_METHOD(MenuItemExecuted, NO_PARAMETER)
				CLASS_MEMBER_METHOD(GetOpeningMenu, NO_PARAMETER)
				CLASS_MEMBER_METHOD(MenuOpened, {L"menu"})
				CLASS_MEMBER_METHOD(MenuClosed, {L"menu"})
			END_INTERFACE_MEMBER(IGuiMenuService)

			BEGIN_ENUM_ITEM(IGuiMenuService::Direction)
				ENUM_ITEM_NAMESPACE(IGuiMenuService)
				ENUM_NAMESPACE_ITEM(Horizontal)
				ENUM_NAMESPACE_ITEM(Vertical)
			END_ENUM_ITEM(IGuiMenuService::Direction)

			BEGIN_CLASS_MEMBER(GuiMenu)
				CLASS_MEMBER_BASE(GuiPopup)
				CLASS_MEMBER_CONSTRUCTOR(GuiMenu*(GuiMenu::IStyleController* _ GuiControl*), {L"styleController" _ L"owner"})

				CLASS_MEMBER_METHOD(UpdateMenuService, NO_PARAMETER)
				CLASS_MEMBER_METHOD(QueryService, {L"identifier"})
			END_CLASS_MEMBER(GuiMenu)

			BEGIN_CLASS_MEMBER(GuiMenuBar)
				CLASS_MEMBER_BASE(GuiControl)
				CONTROL_CONSTRUCTOR_CONTROLLER(GuiMenuBar)
			END_CLASS_MEMBER(GuiMenuBar)

			BEGIN_CLASS_MEMBER(GuiMenuButton)
				CLASS_MEMBER_BASE(GuiSelectableButton)
				CONTROL_CONSTRUCTOR_CONTROLLER(GuiMenuButton)

				CLASS_MEMBER_PROPERTY_GUIEVENT_FAST(Image)
				CLASS_MEMBER_PROPERTY_GUIEVENT_FAST(ShortcutText)
				CLASS_MEMBER_PROPERTY_READONLY_FAST(SubMenu)
				CLASS_MEMBER_PROPERTY_READONLY_FAST(OwnedSubMenu)
				CLASS_MEMBER_PROPERTY_GUIEVENT_FAST(SubMenuOpening)
				CLASS_MEMBER_PROPERTY_FAST(PreferredMenuClientSize)
				CLASS_MEMBER_PROPERTY_FAST(CascadeAction)

				CLASS_MEMBER_METHOD(IsSubMenuExists, NO_PARAMETER)
				CLASS_MEMBER_METHOD(CreateSubMenu, {L"subMenuStyleController"})
				CLASS_MEMBER_METHOD(SetSubMenu, {L"value" _ L"owned"})
			END_CLASS_MEMBER(GuiMenuButton)

			BEGIN_INTERFACE_MEMBER_NOPROXY(GuiMenuButton::IStyleController)
				CLASS_MEMBER_BASE(GuiSelectableButton::IStyleController)

				CLASS_MEMBER_METHOD(CreateSubMenuStyleController, NO_PARAMETER)
				CLASS_MEMBER_METHOD(SetSubMenuExisting, {L"value"})
				CLASS_MEMBER_METHOD(SetSubMenuOpening, {L"value"})
				CLASS_MEMBER_METHOD(GetSubMenuHost, NO_PARAMETER)
				CLASS_MEMBER_METHOD(SetImage, {L"value"})
				CLASS_MEMBER_METHOD(SetShortcutText, {L"value"})
			END_INTERFACE_MEMBER(GuiMenuButton::IStyleController)

			BEGIN_INTERFACE_MEMBER_NOPROXY(INodeProviderCallback)
				CLASS_MEMBER_BASE(IDescriptable)

				CLASS_MEMBER_METHOD(OnAttached, {L"provider"})
				CLASS_MEMBER_METHOD(OnBeforeItemModified, {L"parentNode" _ L"start" _ L"count" _ L"newCount"})
				CLASS_MEMBER_METHOD(OnAfterItemModified, {L"parentNode" _ L"start" _ L"count" _ L"newCount"})
				CLASS_MEMBER_METHOD(OnItemExpanded, {L"node"})
				CLASS_MEMBER_METHOD(OnItemCollapsed, {L"node"})
			END_INTERFACE_MEMBER(INodeProviderCallback)

			BEGIN_INTERFACE_MEMBER(INodeProvider)
				CLASS_MEMBER_BASE(IDescriptable)

				CLASS_MEMBER_PROPERTY_FAST(Expanding)
				CLASS_MEMBER_PROPERTY_READONLY_FAST(ChildCount)
				CLASS_MEMBER_PROPERTY_READONLY_FAST(Parent)

				CLASS_MEMBER_METHOD(CalculateTotalVisibleNodes, NO_PARAMETER)
				CLASS_MEMBER_METHOD(GetChild, {L"index"})
				CLASS_MEMBER_METHOD(Increase, NO_PARAMETER)
				CLASS_MEMBER_METHOD(Release, NO_PARAMETER)
			END_INTERFACE_MEMBER(INodeProvider)

			BEGIN_INTERFACE_MEMBER(INodeRootProvider)
				CLASS_MEMBER_BASE(IDescriptable)

				CLASS_MEMBER_PROPERTY_READONLY_FAST(RootNode)

				CLASS_MEMBER_METHOD(CanGetNodeByVisibleIndex, NO_PARAMETER)
				CLASS_MEMBER_METHOD(GetNodeByVisibleIndex, {L"index"})
				CLASS_MEMBER_METHOD(AttachCallback, {L"value"})
				CLASS_MEMBER_METHOD(DetachCallback, {L"value"})
				CLASS_MEMBER_METHOD(GetTextValue, { L"node" })
				CLASS_MEMBER_METHOD(GetBindingValue, { L"node" })
				CLASS_MEMBER_METHOD(RequestView, {L"identifier"})
			END_INTERFACE_MEMBER(INodeRootProvider)

			BEGIN_INTERFACE_MEMBER(INodeItemView)
				INTERFACE_IDENTIFIER(vl::presentation::controls::tree::INodeItemView)

				CLASS_MEMBER_METHOD(RequestNode, {L"index"})
				CLASS_MEMBER_METHOD(ReleaseNode, {L"node"})
				CLASS_MEMBER_METHOD(CalculateNodeVisibilityIndex, {L"node"})
			END_INTERFACE_MEMBER(INodeItemView)

			BEGIN_CLASS_MEMBER(MemoryNodeProvider)
				CLASS_MEMBER_BASE(INodeProvider)
				CLASS_MEMBER_CONSTRUCTOR(Ptr<MemoryNodeProvider>(), NO_PARAMETER)
				CLASS_MEMBER_CONSTRUCTOR(Ptr<MemoryNodeProvider>(Ptr<DescriptableObject>), {L"data"})

				CLASS_MEMBER_PROPERTY_FAST(Data)

				CLASS_MEMBER_METHOD(NotifyDataModified, NO_PARAMETER)
				CLASS_MEMBER_METHOD_RENAME(GetChildren, Children, NO_PARAMETER)
				CLASS_MEMBER_PROPERTY_READONLY(Children, GetChildren)
			END_CLASS_MEMBER(MemoryNodeProvider)

			BEGIN_CLASS_MEMBER(NodeRootProviderBase)
				CLASS_MEMBER_BASE(INodeRootProvider)
			END_CLASS_MEMBER(NodeRootProviderBase)

			BEGIN_CLASS_MEMBER(MemoryNodeRootProvider)
				CLASS_MEMBER_BASE(MemoryNodeProvider)
				CLASS_MEMBER_BASE(NodeRootProviderBase)

				CLASS_MEMBER_PROPERTY_READONLY_FAST(RootNode)

				CLASS_MEMBER_METHOD(GetMemoryNode, {L"node"})
			END_CLASS_MEMBER(MemoryNodeRootProvider)

			BEGIN_CLASS_MEMBER(GuiVirtualTreeListControl)
				CLASS_MEMBER_BASE(GuiSelectableListControl)
				CLASS_MEMBER_CONSTRUCTOR(GuiVirtualTreeListControl*(GuiVirtualTreeListControl::IStyleProvider* _ Ptr<INodeRootProvider>), {L"styleProvider" _ L"rootNodeProvider"})

				CLASS_MEMBER_GUIEVENT(NodeLeftButtonDown)
				CLASS_MEMBER_GUIEVENT(NodeLeftButtonUp)
				CLASS_MEMBER_GUIEVENT(NodeLeftButtonDoubleClick)
				CLASS_MEMBER_GUIEVENT(NodeMiddleButtonDown)
				CLASS_MEMBER_GUIEVENT(NodeMiddleButtonUp)
				CLASS_MEMBER_GUIEVENT(NodeMiddleButtonDoubleClick)
				CLASS_MEMBER_GUIEVENT(NodeRightButtonDown)
				CLASS_MEMBER_GUIEVENT(NodeRightButtonUp)
				CLASS_MEMBER_GUIEVENT(NodeRightButtonDoubleClick)
				CLASS_MEMBER_GUIEVENT(NodeMouseMove)
				CLASS_MEMBER_GUIEVENT(NodeMouseEnter)
				CLASS_MEMBER_GUIEVENT(NodeMouseLeave)
				CLASS_MEMBER_GUIEVENT(NodeExpanded)
				CLASS_MEMBER_GUIEVENT(NodeCollapsed)

				CLASS_MEMBER_PROPERTY_READONLY_FAST(NodeItemView)
				CLASS_MEMBER_PROPERTY_READONLY_FAST(NodeRootProvider)
			END_CLASS_MEMBER(GuiVirtualTreeListControl)

			BEGIN_INTERFACE_MEMBER(ITreeViewItemView)
				INTERFACE_IDENTIFIER(vl::presentation::controls::tree::ITreeViewItemView)

				CLASS_MEMBER_METHOD(GetNodeImage, {L"node"})
			END_INTERFACE_MEMBER(ITreeViewItemView)

			BEGIN_CLASS_MEMBER(TreeViewItem)
				CLASS_MEMBER_CONSTRUCTOR(Ptr<TreeViewItem>(), NO_PARAMETER)
				CLASS_MEMBER_CONSTRUCTOR(Ptr<TreeViewItem>(const Ptr<GuiImageData>&, const WString&), {L"image" _ L"text"})

				CLASS_MEMBER_FIELD(image)
				CLASS_MEMBER_FIELD(text)
				CLASS_MEMBER_FIELD(tag)
			END_CLASS_MEMBER(TreeViewItem)

			BEGIN_CLASS_MEMBER(TreeViewItemRootProvider)
				CLASS_MEMBER_BASE(MemoryNodeRootProvider)
				CLASS_MEMBER_CONSTRUCTOR(Ptr<TreeViewItemRootProvider>(), NO_PARAMETER)

				CLASS_MEMBER_METHOD(GetTreeViewData, {L"node"})
				CLASS_MEMBER_METHOD(SetTreeViewData, {L"node" _ L"value"})
				CLASS_MEMBER_METHOD(UpdateTreeViewData, {L"node"})
			END_CLASS_MEMBER(TreeViewItemRootProvider)

			BEGIN_CLASS_MEMBER(GuiVirtualTreeView)
				CLASS_MEMBER_BASE(GuiVirtualTreeListControl)
				CLASS_MEMBER_CONSTRUCTOR(GuiVirtualTreeView*(GuiVirtualTreeView::IStyleProvider* _ Ptr<INodeRootProvider>), {L"styleProvider" _ L"rootNodeProvider"})

				CLASS_MEMBER_PROPERTY_READONLY_FAST(TreeViewStyleProvider)
			END_CLASS_MEMBER(GuiVirtualTreeView)

			BEGIN_INTERFACE_MEMBER_NOPROXY(GuiVirtualTreeView::IStyleProvider)
				CLASS_MEMBER_BASE(GuiVirtualTreeListControl::IStyleProvider)

				CLASS_MEMBER_PROPERTY_READONLY_FAST(TextColor)

				CLASS_MEMBER_METHOD(CreateItemBackground, NO_PARAMETER)
				CLASS_MEMBER_METHOD(CreateItemExpandingDecorator, NO_PARAMETER)
			END_INTERFACE_MEMBER(GuiVirtualTreeView::IStyleProvider)

			BEGIN_CLASS_MEMBER(GuiTreeView)
				CLASS_MEMBER_BASE(GuiVirtualTreeView)
				CONTROL_CONSTRUCTOR_PROVIDER(GuiTreeView)

				CLASS_MEMBER_METHOD_RENAME(GetNodes, Nodes, NO_PARAMETER)
				CLASS_MEMBER_PROPERTY_READONLY(Nodes, GetNodes)
				CLASS_MEMBER_PROPERTY_EVENT_READONLY_FAST(SelectedItem, SelectionChanged)
			END_CLASS_MEMBER(GuiTreeView)

			BEGIN_CLASS_MEMBER(GuiComboBoxBase)
				CLASS_MEMBER_BASE(GuiMenuButton)
				CONTROL_CONSTRUCTOR_CONTROLLER(GuiComboBoxBase)

				CLASS_MEMBER_GUIEVENT(ItemSelected)
			END_CLASS_MEMBER(GuiComboBoxBase)

			BEGIN_INTERFACE_MEMBER_NOPROXY(GuiComboBoxBase::IStyleController)
				CLASS_MEMBER_BASE(GuiMenuButton::IStyleController)
				
				CLASS_MEMBER_METHOD(SetCommandExecutor, {L"value"})
				CLASS_MEMBER_METHOD(OnItemSelected, NO_PARAMETER)
			END_INTERFACE_MEMBER(GuiComboBoxBase::IStyleController)

			BEGIN_CLASS_MEMBER(GuiComboBoxListControl)
				CLASS_MEMBER_BASE(GuiComboBoxBase)
				CLASS_MEMBER_CONSTRUCTOR(GuiComboBoxListControl*(GuiComboBoxListControl::IStyleController* _ GuiSelectableListControl*), {L"styleController" _ L"containedListControl"})

				CLASS_MEMBER_PROPERTY_READONLY_FAST(ContainedListControl)
				CLASS_MEMBER_PROPERTY_GUIEVENT_FAST(ItemTemplate)
				CLASS_MEMBER_PROPERTY_GUIEVENT_FAST(SelectedIndex)
				CLASS_MEMBER_PROPERTY_EVENT_READONLY_FAST(SelectedItem, SelectedIndexChanged)
				CLASS_MEMBER_PROPERTY_READONLY_FAST(ItemProvider)
			END_CLASS_MEMBER(GuiComboBoxListControl)

			BEGIN_INTERFACE_MEMBER_NOPROXY(GuiComboBoxListControl::IStyleController)
				CLASS_MEMBER_BASE(GuiComboBoxBase::IStyleController)
				
				CLASS_MEMBER_METHOD(SetTextVisible, {L"value"})
			END_INTERFACE_MEMBER(GuiComboBoxListControl::IStyleController)

			BEGIN_CLASS_MEMBER(GuiToolstripCommand)
				CLASS_MEMBER_BASE(GuiComponent)
				CLASS_MEMBER_CONSTRUCTOR(GuiToolstripCommand*(), NO_PARAMETER)

				CLASS_MEMBER_GUIEVENT(Executed)
				CLASS_MEMBER_GUIEVENT(DescriptionChanged)

				CLASS_MEMBER_PROPERTY_EVENT_FAST(Image, DescriptionChanged)
				CLASS_MEMBER_PROPERTY_EVENT_FAST(Text, DescriptionChanged)
				CLASS_MEMBER_PROPERTY_EVENT_FAST(Shortcut, DescriptionChanged)
				CLASS_MEMBER_PROPERTY_EVENT_FAST(ShortcutBuilder, DescriptionChanged)
				CLASS_MEMBER_PROPERTY_EVENT_FAST(Enabled, DescriptionChanged)
				CLASS_MEMBER_PROPERTY_EVENT_FAST(Selected, DescriptionChanged)
			END_CLASS_MEMBER(GuiToolstripCommand)

			BEGIN_CLASS_MEMBER(GuiToolstripMenu)
				CLASS_MEMBER_BASE(GuiMenu)
				CLASS_MEMBER_CONSTRUCTOR(GuiToolstripMenu*(GuiToolstripMenu::IStyleController* _ GuiControl*), {L"styleController" _ L"owner"})

				CLASS_MEMBER_PROPERTY_READONLY_FAST(ToolstripItems)
			END_CLASS_MEMBER(GuiToolstripMenu)

			BEGIN_CLASS_MEMBER(GuiToolstripMenuBar)
				CLASS_MEMBER_BASE(GuiMenuBar)
				CONTROL_CONSTRUCTOR_CONTROLLER(GuiToolstripMenuBar)
				
				CLASS_MEMBER_PROPERTY_READONLY_FAST(ToolstripItems)
			END_CLASS_MEMBER(GuiToolstripMenuBar)

			BEGIN_CLASS_MEMBER(GuiToolstripToolBar)
				CLASS_MEMBER_BASE(GuiControl)
				CONTROL_CONSTRUCTOR_CONTROLLER(GuiToolstripToolBar)
				
				CLASS_MEMBER_PROPERTY_READONLY_FAST(ToolstripItems)
			END_CLASS_MEMBER(GuiToolstripToolBar)

			BEGIN_CLASS_MEMBER(GuiToolstripButton)
				CLASS_MEMBER_BASE(GuiMenuButton)
				CONTROL_CONSTRUCTOR_CONTROLLER(GuiToolstripButton)

				CLASS_MEMBER_PROPERTY_FAST(Command)
				CLASS_MEMBER_PROPERTY_READONLY_FAST(ToolstripSubMenu)

				CLASS_MEMBER_METHOD(EnsureToolstripSubMenu, NO_PARAMETER)
				CLASS_MEMBER_METHOD(CreateToolstripSubMenu, {L"subMenuStyleController"})
			END_CLASS_MEMBER(GuiToolstripButton)

			BEGIN_CLASS_MEMBER(GuiDocumentItem)
				CLASS_MEMBER_CONSTRUCTOR(Ptr<GuiDocumentItem>(const WString&), { L"name" })

				CLASS_MEMBER_PROPERTY_READONLY_FAST(Container)
				CLASS_MEMBER_PROPERTY_READONLY_FAST(Name)
			END_CLASS_MEMBER(GuiDocumentItem)

			BEGIN_CLASS_MEMBER(GuiDocumentCommonInterface)
				CLASS_MEMBER_PROPERTY_FAST(Document)
				CLASS_MEMBER_PROPERTY_FAST(EditMode)

				CLASS_MEMBER_GUIEVENT(ActiveHyperlinkChanged)
				CLASS_MEMBER_GUIEVENT(ActiveHyperlinkExecuted)
				CLASS_MEMBER_GUIEVENT(SelectionChanged)

				CLASS_MEMBER_METHOD(AddDocumentItem, { L"value" })
				CLASS_MEMBER_METHOD(RemoveDocumentItem, { L"value" })
				CLASS_MEMBER_PROPERTY_READONLY_FAST(DocumentItems)

				CLASS_MEMBER_PROPERTY_READONLY_FAST(CaretBegin)
				CLASS_MEMBER_PROPERTY_READONLY_FAST(CaretEnd)
				CLASS_MEMBER_PROPERTY_READONLY_FAST(ActiveHyperlinkReference)
				CLASS_MEMBER_PROPERTY_EVENT_FAST(SelectionText, SelectionChanged)
				CLASS_MEMBER_PROPERTY_EVENT_FAST(SelectionModel, SelectionChanged)

				CLASS_MEMBER_METHOD(SetCaret, {L"begin" _ L"end" _ L"frontSide"})
				CLASS_MEMBER_METHOD(CalculateCaretFromPoint, {L"point"})
				CLASS_MEMBER_METHOD(GetCaretBounds, {L"caret" _ L"frontSide"})
				CLASS_MEMBER_METHOD(NotifyParagraphUpdated, {L"index" _ L"oldCount" _ L"newCount" _ L"updatedText"})
				CLASS_MEMBER_METHOD(EditRun, {L"begin" _ L"end" _ L"model"})
				CLASS_MEMBER_METHOD(EditText, {L"begin" _ L"end" _ L"frontSide" _ L"text"})
				CLASS_MEMBER_METHOD(EditStyle, {L"begin" _ L"end" _ L"style"})
				CLASS_MEMBER_METHOD(EditImage, {L"begin" _ L"end" _ L"image"})
				CLASS_MEMBER_METHOD(EditImage, {L"paragraphIndex" _ L"begin" _ L"end" _ L"reference" _ L"normalStyleName" _ L"activeStyleName"})
				CLASS_MEMBER_METHOD(RemoveHyperlink, {L"paragraphIndex" _ L"begin" _ L"end"})
				CLASS_MEMBER_METHOD(EditStyleName, {L"begin" _ L"end" _ L"styleName"})
				CLASS_MEMBER_METHOD(RemoveStyleName, {L"begin" _ L"end" _ L"image"})
				CLASS_MEMBER_METHOD(RenameStyle, {L"oldStyleName" _ L"newStyleName"})
				CLASS_MEMBER_METHOD(ClearStyle, {L"begin" _ L"end"})
				CLASS_MEMBER_METHOD(SummarizeStyle, {L"begin" _ L"end"})
				CLASS_MEMBER_METHOD(SetParagraphAlignment, {L"begin" _ L"end" _ L"alignments"})
				CLASS_MEMBER_METHOD(SelectAll, NO_PARAMETER)
				CLASS_MEMBER_METHOD(CanCut, NO_PARAMETER)
				CLASS_MEMBER_METHOD(CanCopy, NO_PARAMETER)
				CLASS_MEMBER_METHOD(CanPaste, NO_PARAMETER)
				CLASS_MEMBER_METHOD(Cut, NO_PARAMETER)
				CLASS_MEMBER_METHOD(Copy, NO_PARAMETER)
				CLASS_MEMBER_METHOD(Paste, NO_PARAMETER)
				CLASS_MEMBER_METHOD(CanUndo, NO_PARAMETER)
				CLASS_MEMBER_METHOD(CanRedo, NO_PARAMETER)
				CLASS_MEMBER_METHOD(ClearUndoRedo, NO_PARAMETER)
				CLASS_MEMBER_METHOD(NotifyModificationSaved, NO_PARAMETER)
				CLASS_MEMBER_METHOD(Undo, NO_PARAMETER)
				CLASS_MEMBER_METHOD(Redo, NO_PARAMETER)
			END_CLASS_MEMBER(GuiDocumentCommonInterface)

			BEGIN_ENUM_ITEM(GuiDocumentCommonInterface::EditMode)
				ENUM_ITEM_NAMESPACE(GuiDocumentCommonInterface)
				ENUM_NAMESPACE_ITEM(ViewOnly)
				ENUM_NAMESPACE_ITEM(Selectable)
				ENUM_NAMESPACE_ITEM(Editable)
			END_ENUM_ITEM(GuiDocumentCommonInterface::EditMode)

			BEGIN_CLASS_MEMBER(GuiDocumentViewer)
				CLASS_MEMBER_BASE(GuiScrollContainer)
				CLASS_MEMBER_BASE(GuiDocumentCommonInterface)
				CONTROL_CONSTRUCTOR_PROVIDER(GuiDocumentViewer)
			END_CLASS_MEMBER(GuiDocumentViewer)

			BEGIN_INTERFACE_MEMBER_NOPROXY(GuiDocumentViewer::IStyleProvider)
				CLASS_MEMBER_BASE(GuiScrollContainer::IStyleProvider)

				CLASS_MEMBER_PROPERTY_READONLY_FAST(BaselineDocument)
				CLASS_MEMBER_PROPERTY_READONLY_FAST(CaretColor)
			END_INTERFACE_MEMBER(GuiDocumentViewer::IStyleProvider)

			BEGIN_CLASS_MEMBER(GuiDocumentLabel)
				CLASS_MEMBER_BASE(GuiControl)
				CLASS_MEMBER_BASE(GuiDocumentCommonInterface)
				CONTROL_CONSTRUCTOR_CONTROLLER(GuiDocumentLabel)
			END_CLASS_MEMBER(GuiDocumentLabel)

			BEGIN_INTERFACE_MEMBER_NOPROXY(GuiDocumentLabel::IStyleController)
				CLASS_MEMBER_BASE(GuiControl::IStyleController)

				CLASS_MEMBER_PROPERTY_READONLY_FAST(BaselineDocument)
			END_INTERFACE_MEMBER(GuiDocumentLabel::IStyleProvider)

			BEGIN_CLASS_MEMBER(GuiTextBoxCommonInterface)
				CLASS_MEMBER_GUIEVENT(SelectionChanged)
				
				CLASS_MEMBER_PROPERTY_FAST(Readonly)
				CLASS_MEMBER_PROPERTY_EVENT_FAST(SelectionText, SelectionChanged)
				CLASS_MEMBER_PROPERTY_EVENT_READONLY_FAST(CaretBegin, SelectionChanged)
				CLASS_MEMBER_PROPERTY_EVENT_READONLY_FAST(CaretEnd, SelectionChanged)
				CLASS_MEMBER_PROPERTY_EVENT_READONLY_FAST(CaretSmall, SelectionChanged)
				CLASS_MEMBER_PROPERTY_EVENT_READONLY_FAST(CaretLarge, SelectionChanged)
				CLASS_MEMBER_PROPERTY_READONLY_FAST(RowCount)
				CLASS_MEMBER_PROPERTY_READONLY_FAST(RowHeight)
				CLASS_MEMBER_PROPERTY_READONLY_FAST(MaxWidth)
				CLASS_MEMBER_PROPERTY_READONLY_FAST(MaxHeight)
				CLASS_MEMBER_PROPERTY_READONLY_FAST(EditVersion)
				CLASS_MEMBER_PROPERTY_READONLY_FAST(Modified)

				CLASS_MEMBER_METHOD(CanCut, NO_PARAMETER)
				CLASS_MEMBER_METHOD(CanCopy, NO_PARAMETER)
				CLASS_MEMBER_METHOD(CanPaste, NO_PARAMETER)
				CLASS_MEMBER_METHOD(Cut, NO_PARAMETER)
				CLASS_MEMBER_METHOD(Copy, NO_PARAMETER)
				CLASS_MEMBER_METHOD(Paste, NO_PARAMETER)
				CLASS_MEMBER_METHOD(SelectAll, NO_PARAMETER)
				CLASS_MEMBER_METHOD(Select, {L"begin" _ L"end"})
				CLASS_MEMBER_METHOD(SetSelectionTextAsKeyInput, {L"value"})
				CLASS_MEMBER_METHOD(GetRowText, {L"row"})
				CLASS_MEMBER_METHOD(GetFragmentText, {L"start" _ L"end"})
				CLASS_MEMBER_METHOD(GetRowWidth, {L"row"})
				CLASS_MEMBER_METHOD(GetTextPosFromPoint, {L"point"})
				CLASS_MEMBER_METHOD(GetPointFromTextPos, {L"pos"})
				CLASS_MEMBER_METHOD(GetRectFromTextPos, {L"pos"})
				CLASS_MEMBER_METHOD(GetNearestTextPos, {L"point"})
				CLASS_MEMBER_METHOD(CanUndo, NO_PARAMETER)
				CLASS_MEMBER_METHOD(CanRedo, NO_PARAMETER)
				CLASS_MEMBER_METHOD(ClearUndoRedo, NO_PARAMETER)
				CLASS_MEMBER_METHOD(NotifyModificationSaved, NO_PARAMETER)
				CLASS_MEMBER_METHOD(Undo, NO_PARAMETER)
				CLASS_MEMBER_METHOD(Redo, NO_PARAMETER)
			END_CLASS_MEMBER(GuiTextBoxCommonInterface)

			BEGIN_CLASS_MEMBER(GuiMultilineTextBox)
				CLASS_MEMBER_BASE(GuiScrollView)
				CLASS_MEMBER_BASE(GuiTextBoxCommonInterface)
				CONTROL_CONSTRUCTOR_PROVIDER(GuiMultilineTextBox)
			END_CLASS_MEMBER(GuiMultilineTextBox)

			BEGIN_CLASS_MEMBER(GuiSinglelineTextBox)
				CLASS_MEMBER_BASE(GuiControl)
				CLASS_MEMBER_BASE(GuiTextBoxCommonInterface)
				CONTROL_CONSTRUCTOR_PROVIDER(GuiSinglelineTextBox)

				CLASS_MEMBER_PROPERTY_FAST(PasswordChar)
			END_CLASS_MEMBER(GuiSinglelineTextBox)

			BEGIN_INTERFACE_MEMBER_NOPROXY(GuiSinglelineTextBox::IStyleProvider)
				CLASS_MEMBER_BASE(GuiControl::IStyleProvider)

				CLASS_MEMBER_METHOD(InstallBackground, {L"background"})
			END_INTERFACE_MEMBER(GuiSinglelineTextBox::IStyleProvider)

			BEGIN_INTERFACE_MEMBER(IDataGridContext)
				CLASS_MEMBER_BASE(IDescriptable)

				CLASS_MEMBER_PROPERTY_READONLY_FAST(ItemProvider)
				CLASS_MEMBER_PROPERTY_READONLY_FAST(ListViewStyleProvider)
				CLASS_MEMBER_PROPERTY_READONLY_FAST(ViewModelContext)
				CLASS_MEMBER_METHOD(RequestSaveData, NO_PARAMETER)
			END_INTERFACE_MEMBER(IDataGridContext)

			BEGIN_INTERFACE_MEMBER(IDataVisualizerFactory)
				CLASS_MEMBER_BASE(IDescriptable)

				CLASS_MEMBER_METHOD(CreateVisualizer, {L"dataGridContext"})
			END_INTERFACE_MEMBER(IDataVisualizerFactory)

			BEGIN_INTERFACE_MEMBER(IDataVisualizer)
				CLASS_MEMBER_BASE(IDescriptable)

				CLASS_MEMBER_PROPERTY_READONLY_FAST(Factory)
				CLASS_MEMBER_PROPERTY_READONLY_FAST(Template)
				CLASS_MEMBER_PROPERTY_READONLY_FAST(DecoratedDataVisualizer)

				CLASS_MEMBER_METHOD(BeforeVisualizeCell, {L"itemProvider" _ L"row" _ L"column"})
				CLASS_MEMBER_METHOD(SetSelected, {L"value"})
			END_INTERFACE_MEMBER(IDataVisualizer)

			BEGIN_INTERFACE_MEMBER(IDataEditorFactory)
				CLASS_MEMBER_BASE(IDescriptable)

				CLASS_MEMBER_METHOD(CreateEditor, {L"dataGridContext"})
			END_INTERFACE_MEMBER(IDataEditorFactory)

			BEGIN_INTERFACE_MEMBER(IDataEditor)
				CLASS_MEMBER_BASE(IDescriptable)

				CLASS_MEMBER_PROPERTY_READONLY_FAST(Factory)
				CLASS_MEMBER_PROPERTY_READONLY_FAST(Template)

				CLASS_MEMBER_METHOD(BeforeEditCell, {L"itemProvider" _ L"row" _ L"column"})
				CLASS_MEMBER_METHOD(ReinstallEditor, NO_PARAMETER)
			END_INTERFACE_MEMBER(IDataEditor)

			BEGIN_INTERFACE_MEMBER(IDataGridView)
				CLASS_MEMBER_BASE(IDescriptable)
				INTERFACE_IDENTIFIER(vl::presentation::controls::list::IDataGridView)

				CLASS_MEMBER_PROPERTY_READONLY_FAST(ViewModelContext)
				CLASS_MEMBER_PROPERTY_READONLY_FAST(SortedColumn)

				CLASS_MEMBER_METHOD(IsColumnSortable, {L"column"})
				CLASS_MEMBER_METHOD(SortByColumn, {L"column" _ L"ascending"})
				CLASS_MEMBER_METHOD(IsSortOrderAscending, NO_PARAMETER)
				CLASS_MEMBER_METHOD(GetCellSpan, {L"row" _ L"column"})
				CLASS_MEMBER_METHOD(GetCellDataVisualizerFactory, {L"row" _ L"column"})
				CLASS_MEMBER_METHOD(VisualizeCell, {L"row" _ L"column" _ L"dataVisualizer"})
				CLASS_MEMBER_METHOD(GetCellDataEditorFactory, {L"row" _ L"column"})
				CLASS_MEMBER_METHOD(EditCell, {L"row" _ L"column" _ L"dataEditor"})
				CLASS_MEMBER_METHOD(SaveCellData, {L"row" _ L"column" _ L"dataEditor"})
			END_INTERFACE_MEMBER(IDataGridView)

			BEGIN_CLASS_MEMBER(GuiVirtualDataGrid)
				CLASS_MEMBER_BASE(GuiVirtualListView)
				CLASS_MEMBER_CONSTRUCTOR(GuiVirtualDataGrid*(GuiVirtualListView::IStyleProvider* _ GuiListControl::IItemProvider*), {L"styleProvider" _ L"itemProvider"})

				CLASS_MEMBER_PROPERTY_GUIEVENT_FAST(SelectedCell)

				CLASS_MEMBER_PROPERTY_READONLY_FAST(ItemProvider)

				CLASS_MEMBER_METHOD(SetViewToDefault, NO_PARAMETER)
			END_CLASS_MEMBER(GuiVirtualDataGrid)

			BEGIN_CLASS_MEMBER(GuiBindableDataVisualizer)
				CLASS_MEMBER_CONSTRUCTOR(Ptr<GuiBindableDataVisualizer>(), NO_PARAMETER)
				CLASS_MEMBER_CONSTRUCTOR(Ptr<GuiBindableDataVisualizer>(Ptr<list::IDataVisualizer>), { L"decoratedVisualizer" })
			END_CLASS_MEMBER(GuiBindableDataVisualizer)

			BEGIN_CLASS_MEMBER(GuiBindableDataVisualizer::Factory)
				CLASS_MEMBER_CONSTRUCTOR(Ptr<GuiBindableDataVisualizer::Factory>(TemplateProperty<templates::GuiGridVisualizerTemplate>), { L"templateFactory"})
			END_CLASS_MEMBER(GuiBindableDataVisualizer::Factory)

			BEGIN_CLASS_MEMBER(GuiBindableDataVisualizer::DecoratedFactory)
				CLASS_MEMBER_CONSTRUCTOR(Ptr<GuiBindableDataVisualizer::DecoratedFactory>(TemplateProperty<templates::GuiGridVisualizerTemplate>, Ptr<list::IDataVisualizerFactory>), { L"templateFactory" _ L"decoratedFactory" })
			END_CLASS_MEMBER(GuiBindableDataVisualizer::DecoratedFactory)

			BEGIN_CLASS_MEMBER(GuiBindableDataEditor)
				CLASS_MEMBER_CONSTRUCTOR(Ptr<GuiBindableDataEditor>(), NO_PARAMETER)
			END_CLASS_MEMBER(GuiBindableDataEditor)

			BEGIN_CLASS_MEMBER(GuiBindableDataEditor::Factory)
				CLASS_MEMBER_CONSTRUCTOR(Ptr<GuiBindableDataEditor::Factory>(TemplateProperty<templates::GuiGridEditorTemplate>), { L"templateFactory" })
			END_CLASS_MEMBER(GuiBindableDataEditor::Factory)

			BEGIN_CLASS_MEMBER(ListViewMainColumnDataVisualizer)
				CLASS_MEMBER_BASE(IDataVisualizer)

				CLASS_MEMBER_PROPERTY_READONLY_FAST(TextElement)
			END_CLASS_MEMBER(ListViewMainColumnDataVisualizer)

			BEGIN_CLASS_MEMBER(ListViewMainColumnDataVisualizer::Factory)
				CLASS_MEMBER_BASE(IDataVisualizerFactory)
				CLASS_MEMBER_CONSTRUCTOR(Ptr<ListViewMainColumnDataVisualizer::Factory>(), NO_PARAMETER)
			END_CLASS_MEMBER(ListViewMainColumnDataVisualizer::Factory)

			BEGIN_CLASS_MEMBER(ListViewSubColumnDataVisualizer)
				CLASS_MEMBER_BASE(IDataVisualizer)

				CLASS_MEMBER_PROPERTY_READONLY_FAST(TextElement)
			END_CLASS_MEMBER(ListViewSubColumnDataVisualizer)

			BEGIN_CLASS_MEMBER(ListViewSubColumnDataVisualizer::Factory)
				CLASS_MEMBER_BASE(IDataVisualizerFactory)
				CLASS_MEMBER_CONSTRUCTOR(Ptr<ListViewSubColumnDataVisualizer::Factory>(), NO_PARAMETER)
			END_CLASS_MEMBER(ListViewSubColumnDataVisualizer::Factory)

			BEGIN_CLASS_MEMBER(HyperlinkDataVisualizer)
				CLASS_MEMBER_BASE(ListViewSubColumnDataVisualizer)
			END_CLASS_MEMBER(HyperlinkDataVisualizer)

			BEGIN_CLASS_MEMBER(HyperlinkDataVisualizer::Factory)
				CLASS_MEMBER_BASE(IDataVisualizerFactory)
				CLASS_MEMBER_CONSTRUCTOR(Ptr<HyperlinkDataVisualizer::Factory>(), NO_PARAMETER)
			END_CLASS_MEMBER(HyperlinkDataVisualizer::Factory)

			BEGIN_CLASS_MEMBER(ImageDataVisualizer)
				CLASS_MEMBER_BASE(IDataVisualizer)

				CLASS_MEMBER_PROPERTY_READONLY_FAST(ImageElement)
			END_CLASS_MEMBER(ImageDataVisualizer)

			BEGIN_CLASS_MEMBER(ImageDataVisualizer::Factory)
				CLASS_MEMBER_BASE(IDataVisualizerFactory)
				CLASS_MEMBER_CONSTRUCTOR(Ptr<ImageDataVisualizer::Factory>(), NO_PARAMETER)
			END_CLASS_MEMBER(ImageDataVisualizer::Factory)

			BEGIN_CLASS_MEMBER(CellBorderDataVisualizer)
				CLASS_MEMBER_BASE(IDataVisualizer)
			END_CLASS_MEMBER(CellBorderDataVisualizer)

			BEGIN_CLASS_MEMBER(CellBorderDataVisualizer::Factory)
				CLASS_MEMBER_BASE(IDataVisualizerFactory)
				CLASS_MEMBER_CONSTRUCTOR(Ptr<CellBorderDataVisualizer::Factory>(Ptr<IDataVisualizerFactory>), {L"decoratedFactory"})
			END_CLASS_MEMBER(CellBorderDataVisualizer::Factory)

			BEGIN_CLASS_MEMBER(NotifyIconDataVisualizer)
				CLASS_MEMBER_BASE(IDataVisualizer)

				CLASS_MEMBER_PROPERTY_READONLY_FAST(LeftImageElement)
				CLASS_MEMBER_PROPERTY_READONLY_FAST(RightImageElement)
			END_CLASS_MEMBER(NotifyIconDataVisualizer)

			BEGIN_CLASS_MEMBER(NotifyIconDataVisualizer::Factory)
				CLASS_MEMBER_BASE(IDataVisualizerFactory)
				CLASS_MEMBER_CONSTRUCTOR(Ptr<NotifyIconDataVisualizer::Factory>(Ptr<IDataVisualizerFactory>), {L"decoratedFactory"})
			END_CLASS_MEMBER(NotifyIconDataVisualizer::Factory)

			BEGIN_CLASS_MEMBER(TextBoxDataEditor)
				CLASS_MEMBER_BASE(IDataEditor)

				CLASS_MEMBER_PROPERTY_READONLY_FAST(TextBox)
			END_CLASS_MEMBER(TextBoxDataEditor)

			BEGIN_CLASS_MEMBER(TextBoxDataEditor::Factory)
				CLASS_MEMBER_BASE(IDataEditorFactory)
				CLASS_MEMBER_CONSTRUCTOR(Ptr<TextBoxDataEditor::Factory>(), NO_PARAMETER)
			END_CLASS_MEMBER(TextBoxDataEditor::Factory)

			BEGIN_CLASS_MEMBER(TextComboBoxDataEditor)
				CLASS_MEMBER_BASE(IDataEditor)

				CLASS_MEMBER_PROPERTY_READONLY_FAST(ComboBoxControl)
				CLASS_MEMBER_PROPERTY_READONLY_FAST(TextListControl)
			END_CLASS_MEMBER(TextComboBoxDataEditor)

			BEGIN_CLASS_MEMBER(TextComboBoxDataEditor::Factory)
				CLASS_MEMBER_BASE(IDataEditorFactory)
				CLASS_MEMBER_CONSTRUCTOR(Ptr<TextComboBoxDataEditor::Factory>(), NO_PARAMETER)
			END_CLASS_MEMBER(TextComboBoxDataEditor::Factory)

			BEGIN_CLASS_MEMBER(DateComboBoxDataEditor)
				CLASS_MEMBER_BASE(IDataEditor)

				CLASS_MEMBER_PROPERTY_READONLY_FAST(ComboBoxControl)
				CLASS_MEMBER_PROPERTY_READONLY_FAST(DatePickerControl)
			END_CLASS_MEMBER(DateComboBoxDataEditor)

			BEGIN_CLASS_MEMBER(DateComboBoxDataEditor::Factory)
				CLASS_MEMBER_BASE(IDataEditorFactory)
				CLASS_MEMBER_CONSTRUCTOR(Ptr<DateComboBoxDataEditor::Factory>(), NO_PARAMETER)
			END_CLASS_MEMBER(DateComboBoxDataEditor::Factory)

			BEGIN_CLASS_MEMBER(GuiDatePicker)
				CLASS_MEMBER_BASE(GuiControl)
				CONTROL_CONSTRUCTOR_PROVIDER(GuiDatePicker)

				CLASS_MEMBER_PROPERTY_EVENT_FAST(Date, DateChanged)
				CLASS_MEMBER_PROPERTY_EVENT_FAST(DateFormat, DateFormatChanged)
				CLASS_MEMBER_PROPERTY_EVENT_FAST(DateLocale, DateLocaleChanged)

				CLASS_MEMBER_GUIEVENT(DateSelected);
				CLASS_MEMBER_GUIEVENT(DateNavigated);
			END_CLASS_MEMBER(GuiDatePicker)

			BEGIN_INTERFACE_MEMBER_NOPROXY(GuiDatePicker::IStyleProvider)
				CLASS_MEMBER_BASE(GuiControl::IStyleProvider)

				CLASS_MEMBER_PROPERTY_READONLY_FAST(BackgroundColor)
				CLASS_MEMBER_PROPERTY_READONLY_FAST(PrimaryTextColor)
				CLASS_MEMBER_PROPERTY_READONLY_FAST(SecondaryTextColor)

				CLASS_MEMBER_METHOD(CreateDateButtonStyle, NO_PARAMETER)
				CLASS_MEMBER_METHOD(CreateTextList, NO_PARAMETER)
				CLASS_MEMBER_METHOD(CreateComboBoxStyle, NO_PARAMETER)
			END_INTERFACE_MEMBER(GuiDatePicker::IStyleProvider)

			BEGIN_CLASS_MEMBER(GuiDateComboBox)
				CLASS_MEMBER_BASE(GuiComboBoxBase)
				CLASS_MEMBER_CONSTRUCTOR(GuiDateComboBox*(GuiDateComboBox::IStyleController* _ GuiDatePicker*), {L"styleController" _ L"datePicker"})

				CLASS_MEMBER_PROPERTY_EVENT_FAST(SelectedDate, SelectedDateChanged)
				CLASS_MEMBER_PROPERTY_READONLY_FAST(DatePicker)
			END_CLASS_MEMBER(GuiDateComboBox)

			BEGIN_CLASS_MEMBER(GuiBindableTextList)
				CLASS_MEMBER_BASE(GuiVirtualTextList)
				CLASS_MEMBER_CONSTRUCTOR(GuiBindableTextList*(GuiBindableTextList::IStyleProvider*), {L"styleProvider"})

				CLASS_MEMBER_PROPERTY_FAST(ItemSource)
				CLASS_MEMBER_PROPERTY_GUIEVENT_FAST(TextProperty)
				CLASS_MEMBER_PROPERTY_GUIEVENT_FAST(CheckedProperty)
				CLASS_MEMBER_PROPERTY_EVENT_READONLY_FAST(SelectedItem, SelectionChanged)
			END_CLASS_MEMBER(GuiBindableTextList)

			BEGIN_CLASS_MEMBER(GuiBindableListView)
				CLASS_MEMBER_BASE(GuiVirtualListView)
				CLASS_MEMBER_CONSTRUCTOR(GuiBindableListView*(GuiBindableListView::IStyleProvider*), {L"styleProvider"})

				CLASS_MEMBER_PROPERTY_READONLY_FAST(DataColumns)
				CLASS_MEMBER_PROPERTY_READONLY_FAST(Columns)
				CLASS_MEMBER_PROPERTY_FAST(ItemSource)
				CLASS_MEMBER_PROPERTY_GUIEVENT_FAST(LargeImageProperty)
				CLASS_MEMBER_PROPERTY_GUIEVENT_FAST(SmallImageProperty)
				CLASS_MEMBER_PROPERTY_EVENT_READONLY_FAST(SelectedItem, SelectionChanged)
			END_CLASS_MEMBER(GuiBindableListView)

			BEGIN_CLASS_MEMBER(GuiBindableTreeView)
				CLASS_MEMBER_BASE(GuiVirtualTreeView)
				CLASS_MEMBER_CONSTRUCTOR(GuiBindableTreeView*(GuiBindableTreeView::IStyleProvider*), {L"styleProvider"})
				
				CLASS_MEMBER_PROPERTY_FAST(ItemSource)
				CLASS_MEMBER_PROPERTY_GUIEVENT_FAST(TextProperty)
				CLASS_MEMBER_PROPERTY_GUIEVENT_FAST(ImageProperty)
				CLASS_MEMBER_PROPERTY_GUIEVENT_FAST(ChildrenProperty)
				CLASS_MEMBER_PROPERTY_EVENT_READONLY_FAST(SelectedItem, SelectionChanged)
			END_CLASS_MEMBER(GuiBindableTreeView)

			BEGIN_INTERFACE_MEMBER(IDataFilterCallback)
				CLASS_MEMBER_BASE(IDescriptable)

				CLASS_MEMBER_PROPERTY_READONLY_FAST(ItemProvider)
				CLASS_MEMBER_METHOD(OnFilterChanged, NO_PARAMETER)
			END_INTERFACE_MEMBER(IDataFilterCallback)

			BEGIN_INTERFACE_MEMBER(IDataFilter)
				CLASS_MEMBER_BASE(IDescriptable)

				CLASS_MEMBER_METHOD(SetCallback, { L"value" })
				CLASS_MEMBER_METHOD(Filter, { L"row" })
			END_INTERFACE_MEMBER(IDataFilter)

			BEGIN_INTERFACE_MEMBER(IDataSorter)
				CLASS_MEMBER_BASE(IDescriptable)

				CLASS_MEMBER_METHOD(Compare, { L"row1" _ L"row2" })
			END_INTERFACE_MEMBER(IDataSorter)

			BEGIN_CLASS_MEMBER(DataFilterBase)
				CLASS_MEMBER_BASE(IDataFilter)
			END_CLASS_MEMBER(DataFilterBase)

			BEGIN_CLASS_MEMBER(DataMultipleFilter)
				CLASS_MEMBER_BASE(DataFilterBase)

				CLASS_MEMBER_METHOD(AddSubFilter, {L"value"})
				CLASS_MEMBER_METHOD(RemoveSubFilter, {L"value"})
			END_CLASS_MEMBER(DataMultipleFilter)

			BEGIN_CLASS_MEMBER(DataAndFilter)
				CLASS_MEMBER_BASE(DataMultipleFilter)
				CLASS_MEMBER_CONSTRUCTOR(Ptr<DataAndFilter>(), NO_PARAMETER)
			END_CLASS_MEMBER(DataAndFilter)

			BEGIN_CLASS_MEMBER(DataOrFilter)
				CLASS_MEMBER_BASE(DataMultipleFilter)
				CLASS_MEMBER_CONSTRUCTOR(Ptr<DataOrFilter>(), NO_PARAMETER)
			END_CLASS_MEMBER(DataOrFilter)

			BEGIN_CLASS_MEMBER(DataNotFilter)
				CLASS_MEMBER_BASE(DataFilterBase)
				CLASS_MEMBER_CONSTRUCTOR(Ptr<DataNotFilter>(), NO_PARAMETER)

				CLASS_MEMBER_METHOD(SetSubFilter, {L"value"})
			END_CLASS_MEMBER(DataNotFilter)

			BEGIN_CLASS_MEMBER(DataMultipleSorter)
				CLASS_MEMBER_BASE(IDataSorter)
				CLASS_MEMBER_CONSTRUCTOR(Ptr<DataMultipleSorter>(), NO_PARAMETER)

				CLASS_MEMBER_METHOD(SetLeftSorter, {L"value"})
				CLASS_MEMBER_METHOD(SetRightSorter, {L"value"})
			END_CLASS_MEMBER(DataMultipleSorter)

			BEGIN_CLASS_MEMBER(DataReverseSorter)
				CLASS_MEMBER_BASE(DataMultipleSorter)
				CLASS_MEMBER_CONSTRUCTOR(Ptr<DataReverseSorter>(), NO_PARAMETER)
				
				CLASS_MEMBER_METHOD(SetSubSorter, {L"value"})
			END_CLASS_MEMBER(DataReverseSorter)

			BEGIN_CLASS_MEMBER(DataColumn)
				CLASS_MEMBER_CONSTRUCTOR(Ptr<DataColumn>(), NO_PARAMETER)

				CLASS_MEMBER_PROPERTY_FAST(Text)
				CLASS_MEMBER_PROPERTY_FAST(Size)
				CLASS_MEMBER_PROPERTY_FAST(Popup)
				CLASS_MEMBER_PROPERTY_FAST(InherentFilter)
				CLASS_MEMBER_PROPERTY_FAST(InherentSorter)
				CLASS_MEMBER_PROPERTY_FAST(VisualizerFactory)
				CLASS_MEMBER_PROPERTY_FAST(EditorFactory)

				CLASS_MEMBER_METHOD(GetCellText, { L"row" })
				CLASS_MEMBER_METHOD(GetCellValue, { L"row" })
				CLASS_MEMBER_METHOD(SetCellValue, { L"row" _ L"value" })
				CLASS_MEMBER_PROPERTY_GUIEVENT_FAST(TextProperty)
				CLASS_MEMBER_PROPERTY_GUIEVENT_FAST(ValueProperty)
			END_CLASS_MEMBER(DataColumn)

			BEGIN_CLASS_MEMBER(GuiBindableDataGrid)
				CLASS_MEMBER_BASE(GuiVirtualDataGrid)
				CLASS_MEMBER_CONSTRUCTOR(GuiBindableDataGrid*(GuiBindableDataGrid::IStyleProvider*, const Value&), {L"styleProvider" _ L"viewModelContext"})

				CLASS_MEMBER_PROPERTY_READONLY_FAST(DataColumns)
				CLASS_MEMBER_PROPERTY_READONLY_FAST(Columns)
				CLASS_MEMBER_PROPERTY_FAST(ItemSource)
				CLASS_MEMBER_PROPERTY_GUIEVENT_FAST(LargeImageProperty)
				CLASS_MEMBER_PROPERTY_GUIEVENT_FAST(SmallImageProperty)
				CLASS_MEMBER_PROPERTY_EVENT_READONLY_FAST(SelectedRowValue, SelectedCellChanged)
				CLASS_MEMBER_PROPERTY_EVENT_READONLY_FAST(SelectedCellValue, SelectedCellChanged)
			END_CLASS_MEMBER(GuiBindableDataGrid)

#undef INTERFACE_IDENTIFIER
#undef CONTROL_CONSTRUCTOR_CONTROLLER
#undef INTERFACE_EXTERNALCTOR
#undef _

/***********************************************************************
Type Loader
***********************************************************************/

			class GuiControlsTypeLoader : public Object, public ITypeLoader
			{
			public:
				void Load(ITypeManager* manager)
				{
					GUIREFLECTIONCONTROLS_TYPELIST(ADD_TYPE_INFO)
				}

				void Unload(ITypeManager* manager)
				{
				}
			};

#endif

			bool LoadGuiControlTypes()
			{
#ifndef VCZH_DEBUG_NO_REFLECTION
				ITypeManager* manager=GetGlobalTypeManager();
				if(manager)
				{
					Ptr<ITypeLoader> loader=new GuiControlsTypeLoader;
					return manager->AddTypeLoader(loader);
				}
#endif
				return false;
			}
		}
	}
}
